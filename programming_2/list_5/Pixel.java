package list_5;

public class Pixel extends Dot{
    String color;
    Pixel(){
        x = 0;
        y = 0;
        color = "black";
    }
    Pixel(int x, int y){
        this.x = x;
        this.y = y;
    }
    
    Pixel(int x, int y, String color){
        super(x, y);
        this.color = color;
    }
    
}
