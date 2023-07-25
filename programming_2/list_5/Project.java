package com.mycompany.list_5;

public abstract class Project {
    int code;
    String title;
    Project(){
        code = 0;
        title = "";
    }
    Project(int n, String s){
        code = n;
        title = s;
    }
}
