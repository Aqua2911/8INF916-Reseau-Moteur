namespace GameApi.Models;

public class GameServer {
    public string Ip { get; set; } = "";
    public int Port { get; set; }
    public int Capacity { get; set; }
    public int Load { get; set; } = 0;

    public string WebSocketUrl => $"ws://{Ip}:{Port}";
}
