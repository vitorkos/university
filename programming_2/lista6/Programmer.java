package com.mycompany.lista6;

public class Programmer implements IEmployee{
    double hours, per_hour;
    Programmer(){
        hours = 0.0; per_hour = 0.0;
    }
    Programmer(double x, double y){
        hours = x; per_hour = y;
    }
    
    @Override
    public double calculateSalary(double h, double ph) {
        return h * ph;
    }    
}
