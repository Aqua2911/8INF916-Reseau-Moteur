namespace GameApi.Models;

public class Player {
    public Guid Uid { get; set; } = Guid.NewGuid(); // FIXME : not sure about this
    public string Username { get; set; } = "";

    public Player(string username) {
        Username = username;
    }
}
