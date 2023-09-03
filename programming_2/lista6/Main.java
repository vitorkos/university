package com.mycompany.lista6;

import java.util.ArrayList;
import java.util.LinkedList;


public class Main {
    public static void main(String[] args) {
        ArrayList<IEmployee> employee = new ArrayList<IEmployee>();
        
        Programmer p1 = new Programmer(180.0, 10.0);
        Programmer p2 = new Programmer(150.0, 20.0);
        Programmer p3 = new Programmer(130.0, 9.0);
        
        Manager m1 = new Manager(180.0, 10.0);
        Manager m2 = new Manager(150.0, 20.0);
        Manager m3 = new Manager(130.0, 9.0);
    
        //employee.add(p1, p2, p3);
    }
}
