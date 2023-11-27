package list_2;

class Main {
    public static void main(String[] args) {
        System.out.println("-Car-");
        Car car = new Car("fiat", "147", 1976, 20);
                
        while(car.speed < 200)
        {
            car.accelerate();
            System.out.println(car.speed);
        }
        while(car.speed != 140){
            car.brake();
            System.out.println(car.speed);
        }
        
        System.out.println("-Book-");
        Book book = new Book();
        book.author.name = "Kafka";
        book.author.gender = "Fiction/ Suspense";
        book.title = "The metamorfosis";
        book.pages = 328;
        book.publishing_company = "antifagia";
                
        System.out.println(book.title);
        System.out.println(book.author.name);
        System.out.println(book.author.gender);
        System.out.println(book.pages);
        System.out.println(book.publishing_company);
        
        System.out.println("-Programmer1-");
        Programmer programmer = new Programmer(2000.0, 20.0);
                       
        System.out.println(programmer.calculateSalary());
        
        System.out.println("-Line-");
        Line line = new Line(10);
        for(Integer i = 0; i < line.length; i++){
            System.out.println("|");
        }
        
        System.out.println("-Student-");
        Student student1 = new Student("Vitor", 123);
        Student student2 = new Student("Maria", 321);
        Duo duo = new Duo(student1, student2);
        duo.showStudent1();
        duo.showStudent2();        
        
        System.out.println("-ProgrammerHours");
        ProgrammerHours programmer_hours = new ProgrammerHours(12.0, 45.0);
        
        System.out.println(programmer_hours.calculateSalary());
    }
}
