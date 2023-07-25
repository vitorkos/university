package com.mycompany.list_5;

public class CharWoman extends Employee{
    double salary_day;
    double worked_days;
    CharWoman(){
        super();
        salary_day = 0;
        worked_days = 0;  
    }
    CharWoman(int sd, int wd){
        salary_day = sd;
        worked_days = wd;
    }

    @Override
    public double calculateSalary() {
        return salary_day * worked_days;
    }
    
    
}
