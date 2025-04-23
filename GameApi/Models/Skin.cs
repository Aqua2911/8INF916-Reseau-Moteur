namespace GameApi.Models;

public class Skin {
    public int Id { get; set; } = 0;
    public string Name { get; set; } = "";
    public int Price { get; set; }

    public Skin(int id, string name, int price) {
        Id    = id;
        Name  = name;
        Price = price;
    }
}