using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.IdentityModel.Tokens;
using System.Text;
using Microsoft.AspNetCore.Authorization;


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

var users = new List<Player>
{
    new Player { Username = "alice" },
    new Player { Username = "bob" }
};

// POST /login
app.MapPost("/login", (Player player) =>
{
    var existing = users.FirstOrDefault(u =>
        u.Username == player.Username);

    if (existing == null)
        return Results.Unauthorized();

    var token = JwtHelper.GenerateToken(player.Username);
    return Results.Ok(new { token });
});

var matchQueue = new List<MatchRequest>();
var sessions = new Dictionary<string, string>(); // username → server IP (later)

app.MapPost("/match", [Authorize] (HttpContext ctx) =>
{
    var username = ctx.User.Identity?.Name;

    if (username == null)
        return Results.Unauthorized();

    matchQueue.Add(new MatchRequest { Username = username });

    // Fake immediate session for now
    sessions[username] = "ws://127.0.0.1:7777"; // temp, static session IP

    return Results.Ok(new { message = "Match request received" });
});

app.MapGet("/session", [Authorize] (HttpContext ctx) =>
{
    var username = ctx.User.Identity?.Name;

    if (username == null)
        return Results.Unauthorized();

    if (sessions.TryGetValue(username, out var sessionUrl))
    {
        return Results.Ok(new { session = sessionUrl });
    }

    return Results.NotFound(new { message = "No session assigned" });
});

app.UseAuthentication();
app.UseAuthorization();

app.Run();
