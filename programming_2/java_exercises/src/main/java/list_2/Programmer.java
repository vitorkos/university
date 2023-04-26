package list_2;

public class Programmer {
    
    Double monthly_salary;
    Double overtime;

    Programmer() 
    {
        monthly_salary = 0.0;
        overtime = 0.0;
    }

    Programmer(Double monthly_salary, Double overtime) 
    {
        this.monthly_salary = monthly_salary;
        this.overtime = overtime;
    }
    Double calculateSalary()
    {
        Double salary = monthly_salary * overtime;
        return salary;
    }
    
}
