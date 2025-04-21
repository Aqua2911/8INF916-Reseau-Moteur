public class MatchRequest {
    public string Username { get; set; }
    public DateTime TimeRequested { get; set; } = DateTime.UtcNow;
}