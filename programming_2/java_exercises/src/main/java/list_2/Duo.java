package list_2;

public class Duo {
    
    Student student1;
    Student student2;
    
    Duo(Student student1, Student student2) {
        this.student1 = student1;
        this.student2 = student2;
    }
    void showStudent1()
    {
        System.out.println("Student 1 : " + student1.getName());
        System.out.println("Student 1 : " + student1.getRegistration());
    }
    void showStudent2(){
        System.out.println("Student 2 : " + student2.getName());
        System.out.println("Student 2 : " + student1.getRegistration());
    }
}
    
