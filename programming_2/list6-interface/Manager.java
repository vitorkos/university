package list_6;

public class Manager implements IEmployee{
    double hours, per_hour;
    Manager(){
        hours = 0.0; per_hour = 0.0;
    }
    Manager(double x, double y){
        hours = x; per_hour = y;
    }

    @Override
    public double calculateSalary(double h, double ph) {
        return ((h * ph)*0.1) + h*ph; 
    }
    
}
