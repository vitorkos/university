namespace Api.Models
{
    public class ToDo{
        public int Id{get; set;}
        public string Task{get; set;}
        public bool IsCompleted{get;set;} = false;
        public DateTime CreatedAt{get;set;} = DateTime.Now;
        public int UserId{get;set;}
        public User? Usuario{get;set;}
        public Category? Categoria{get; set;}

        public ToDo(){
            this.Id = 0;
            this.Task = "";
            
        }
    }
}