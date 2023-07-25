package com.mycompany.list_5;

public class Search extends Project{
    String cnpq_area;
    Double budget;
    Search(){
        super();
        cnpq_area = "";
        budget = 0.0;
    }
    Search(String t,int c, String a, double d){
        super(c, t);
        cnpq_area = a;
        budget = d;
    }
    
}
