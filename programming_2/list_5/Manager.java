package com.mycompany.list_5;

public class Manager extends Employee{
    double monthlySalary;
    Manager(){
        monthlySalary = 0.0;
    }
    Manager(double n){
        monthlySalary = n;
    }

    @Override
    public double calculateSalary() {
        return (monthlySalary * 0.1) + monthlySalary;
    }
    
    
}
