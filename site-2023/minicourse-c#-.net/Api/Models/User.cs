namespace Api.Models
{
    public class User
    {
        public int Id{get; set;}
        public string Name{get; set;}
        public string Email{get; set;}
        public string Password{get; set;}

        public User()
        {
            this.Id = 0;
            this.Name = "";
            this.Email = "";
            this.Password = "";
        }

        public User(int id, string name, string email, string password)
        {
            this.Id = id;
            this.Name = name;
            this.Email = email;
            this.Password = password;
        }
    }
}
