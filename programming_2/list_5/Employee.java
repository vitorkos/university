package list_5;

public abstract class Employee {
    private int code;
    private String name;
    Employee(){
        code = 0;
        name = "";
    }
    Employee(int n, String s){
        code = n;
        name = s;
    }
    
    void setCode(int n){code = n;}
    void setName(String n){name = n;}
    int getCode(){return code;}
    String getName(){return name;}
    public abstract double calculateSalary();
}
