package com.mycompany.list_5;

public class Circle extends Dot{
    Dot dot;
    int radius;
    Circle(){
        dot = new Dot(0, 0);
        radius = 1;
    }
    Circle(int x, int y, int r){
        super(x, y);
        radius = r;
    }
   
}
