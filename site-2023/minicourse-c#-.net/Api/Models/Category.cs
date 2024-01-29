namespace Api.Models
{
    public class Category{
        public int Id{get;set;}
        public string Name{get; set;}
        public string Color{get;set;}
        public int UserId{get;set;}
        public User? Usuario{get;set;}

        public Category()
        {
            this.Id = 0;
            this.Name = "";
            this.Color = "";
        }

        public Category(int id, string name, string color)
        {
            this.Id = id;
            this.Name = name;
            this.Color = color;
        }
    }
}