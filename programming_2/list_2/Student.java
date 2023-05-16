package list_2;

class Student {
    
    String name;
    Integer registration;

    Student()
    {
        name = "";
        registration = 0;
        
    }
    Student(String name, Integer registration) {
        this.name = name;
        this.registration = registration;
    }   
    int getRegistration()
    {
        return registration;
    }
    String getName()
    {
        return name;
    }
}