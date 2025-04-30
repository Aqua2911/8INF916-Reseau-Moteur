using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.IdentityModel.Tokens;
using System.Text;
using Microsoft.AspNetCore.Authorization;
using System.Net.WebSockets;
using GameApi.Models;

var builder = WebApplication.CreateBuilder(args);

builder.Services.AddAuthentication(options =>
{
    options.DefaultAuthenticateScheme = JwtBearerDefaults.AuthenticationScheme;
    options.DefaultChallengeScheme = JwtBearerDefaults.AuthenticationScheme;
})
.AddJwtBearer(options =>
{
    options.RequireHttpsMetadata = false; // For local dev only
    options.SaveToken = true;
    options.TokenValidationParameters = new TokenValidationParameters
    {
        ValidateIssuerSigningKey = true,
        IssuerSigningKey = new SymmetricSecurityKey(
            Encoding.ASCII.GetBytes("ThisIsASuperLongSecretKey1234567890")),
        ValidateIssuer = false,
        ValidateAudience = false
    };
});
builder.Services.AddAuthorization();

var app = builder.Build();

app.UseAuthentication();
app.UseAuthorization();
app.UseWebSockets(); // Enable WebSocket middleware


var users = new List<Player>{
    new Player("alice"),
    new Player("bob"),
    new Player("charlie"),
    new Player("valere")
};
var matchQueue = new List<MatchRequest>();
var sessions = new Dictionary<string, string>(); // username → server IP
var gameServers = new List<GameServer>();
var store = new List<Skin> {
    new Skin(1, "Dragon Sword", 100),
    new Skin(2, "Shadow Cloak", 150),
    new Skin(3, "Golden Crown", 200)
};
var inventory = new Dictionary<string, List<int>>(); // username → purchased skin IDs

var availableStats = new Dictionary<string, StatRule> {
    ["GAMES_WON"] = StatRule.Sum,
    ["CUBES_CLEARED"] = StatRule.Sum,
};

var playerStats = new Dictionary<string, Dictionary<string, int>>(); // username -> (statName -> value)

// initialize stats for all known players
foreach (var player in users)
{
    if (!playerStats.ContainsKey(player.Uid.ToString())) // if missing
    {
        playerStats[player.Uid.ToString()] = new Dictionary<string, int>();
        foreach (var statName in availableStats.Keys)
        {
            playerStats[player.Uid.ToString()][statName] = 0; // init every available stat to 0
        }
    }
}

var achievements = new List<Achievement>
{
    new("first-win", "First Game Won", "GAMES_WON", 1),
    new("veteran", "Cleared 1000 Cubes", "CUBES_CLEARED", 1000),
};

var unlockedAchievements = new Dictionary<string, HashSet<string>>(); // uid -> set of achievement IDs

var waitingPlayers = new List<MatchCandidate>();




// POST /login
app.MapPost("/login", (Player player) =>
{
    var existing = users.FirstOrDefault(u =>
        u.Username == player.Username);

    if (existing == null)
        return Results.Unauthorized();

    var token = JwtHelper.GenerateToken(player.Username, existing.Uid);
    return Results.Ok(new { token, uid = existing.Uid.ToString() });    // FIXME : not sure if tostring is necessary
});



app.MapPost("/match", [Authorize] (HttpContext ctx) =>
{
    Console.WriteLine("Match request received!");

    var uid = ctx.User.FindFirst("uid")?.Value;
    if (uid == null) return Results.Unauthorized();



    // Get player's level (playerMMR)
    if (!playerStats.TryGetValue(uid, out var stats) || !stats.TryGetValue("GAMES_WON", out var playerMMR))
    {
        return Results.BadRequest(new { error = "Missing stat 'GAMES_WON'" });
    }

    var candidate = new MatchCandidate(uid, playerMMR);
    waitingPlayers.Add(candidate);
    Console.WriteLine($"Player {uid} queued with {playerMMR} MMR");

    // Try to find a group of 4 with similar level
    const int LEVEL_TOLERANCE = 3;
    const int PLAYER_PER_MATCH = 4;
    var group = waitingPlayers
        .Where(p => Math.Abs(p.MatchmakingRanking - playerMMR) <= LEVEL_TOLERANCE)
        .Take(PLAYER_PER_MATCH)
        .ToList();

    if (group.Count < PLAYER_PER_MATCH)
        return Results.Ok(new { message = "Waiting for more players..." });

    // Find a server with available space
    var server = gameServers.FirstOrDefault(s => s.Load + PLAYER_PER_MATCH <= s.Capacity);
    if (server == null) return Results.StatusCode(503); // No server

    server.Load += PLAYER_PER_MATCH;

    foreach (var player in group)
    {
        sessions[player.Uid] = server.WebSocketUrl;
        waitingPlayers.RemoveAll(p => p.Uid == player.Uid);

        Console.WriteLine($"Matched {player.Uid} to {server.WebSocketUrl}");
    }
    return Results.Ok(new { session = server.WebSocketUrl });
});

app.MapGet("/session", [Authorize] (HttpContext ctx) =>
{
    var uid = ctx.User.FindFirst("uid")?.Value;
    if (uid == null) return Results.Unauthorized();

    if (sessions.TryGetValue(uid, out var sessionUrl)) {
        return Results.Ok(new { session = sessionUrl });
    }

    return Results.NotFound(new { message = "No session assigned" });
});


app.MapPost("/register-server", (GameServer server) =>
{
    gameServers.Add(server);
    Console.WriteLine($"Registered game server at {server.Ip}:{server.Port}");
    return Results.Ok(new { message = "Server registered" });
});

app.Map("/telemetry", async context =>
{
    if (context.WebSockets.IsWebSocketRequest)
    {
        var ws = await context.WebSockets.AcceptWebSocketAsync();
        Console.WriteLine("Client connected to /telemetry WebSocket");

        var buffer = new byte[1024 * 4];

        while (true)
        {
            var result = await ws.ReceiveAsync(new ArraySegment<byte>(buffer), CancellationToken.None);

            if (result.MessageType == WebSocketMessageType.Close)
            {
                Console.WriteLine("WebSocket closed");
                await ws.CloseAsync(WebSocketCloseStatus.NormalClosure, "Closing", CancellationToken.None);
                break;
            }

            var msg = Encoding.UTF8.GetString(buffer, 0, result.Count);
            Console.WriteLine($"Received telemetry: {msg}");

            // Broadcast to all connected clients if needed
            // For now, echo back to same client:
            var echoBytes = Encoding.UTF8.GetBytes(msg);
            await ws.SendAsync(new ArraySegment<byte>(echoBytes), WebSocketMessageType.Text, true, CancellationToken.None);
        }
    }
    else
    {
        context.Response.StatusCode = 400;
    }
});

app.MapGet("/config", () =>
{
    var config = new
    {
        maxPlayers = 4,
        tickRate = 20,
        networkProtocol = "ENet6"
    };

    return Results.Ok(config);
});


// GET /online → list available skins
app.MapGet("/online", () => Results.Ok(store));


// POST /online/purchase → buy a skin
app.MapPost("/online/purchase", [Authorize] (HttpContext ctx, PurchaseRequest req) =>
{
    var user = ctx.User.Identity?.Name;
    if (user == null) return Results.Unauthorized();

    // find the skin
    if (!store.Any(s => s.Id == req.Id))
        return Results.NotFound(new { error = "Skin not found" });

    // add to inventory
    if (!inventory.ContainsKey(user))
        inventory[user] = new List<int>();
    inventory[user]!.Add(req.Id);

    return Results.Ok(new { success = true });
});

// GET /online/inventory → what this user owns
app.MapGet("/online/inventory", [Authorize] (HttpContext ctx) =>
{
    var user = ctx.User.Identity?.Name;
    if (user == null) return Results.Unauthorized();

    inventory.TryGetValue(user, out var items);
    return Results.Ok(items ?? new List<int>());
});


// POST /stats → increment any stat dynamically
app.MapPost("/stats/{statName}", [Authorize] (HttpContext ctx, string statName, StatUpdateRequest body) =>
{
    var user = ctx.User.Identity!.Name!;
    var player = users.FirstOrDefault(p => p.Username == user);
    if (player == null) return Results.Unauthorized();

    if (!availableStats.TryGetValue(statName, out var rule))
        return Results.BadRequest(new { error = "Stat doesn't exist" });

    var uid = player.Uid.ToString();
    if (!playerStats.TryGetValue(uid, out var stats))
    {
        stats = new Dictionary<string, int>();
        playerStats[uid] = stats;
    }

    stats.TryGetValue(statName, out var current);

    int newValue = rule switch
    {
        StatRule.Sum => current + body.value,
        StatRule.Max => Math.Max(current, body.value),
        StatRule.Min => current == 0 ? body.value : Math.Min(current, body.value),
        _ => current
    };

    stats[statName] = newValue;

    // check achievements...
    foreach (var ach in achievements.Where(a => a.StatKey == statName))
    {
        if (newValue >= ach.Threshold)
        {
            if (!unlockedAchievements.TryGetValue(uid, out var set))
            {
                set = new HashSet<string>();
                unlockedAchievements[uid] = set;
            }

            if (set.Add(ach.Id)) // new unlock
            {
                Console.WriteLine($"Player {uid} unlocked achievement: {ach.Name}");
                // optionally: send a WebSocket event, or store timestamp, etc.
            }
        }
    }

    return Results.Ok(new { updated = statName, value = newValue });
});

// GET /stats/{uid} → get all stats for that user
app.MapGet("/stats/{uid}", (string uid) =>
{
    if (!playerStats.TryGetValue(uid, out var userStats))
        return Results.NotFound(new { error = "No stats for user" });

    return Results.Ok(userStats);
});

// GET /stats/available → show all possible stat names and their rule
app.MapGet("/stats/available", () => Results.Ok(availableStats));

app.MapGet("/achievements/{uid}", (string uid) =>
{
    unlockedAchievements.TryGetValue(uid, out var set);
    var unlocked = set ?? new HashSet<string>();
    var result = achievements.Where(a => unlocked.Contains(a.Id)).ToList();
    return Results.Ok(result);
});


app.Run();
