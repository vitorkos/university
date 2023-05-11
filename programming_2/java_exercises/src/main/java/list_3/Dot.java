package list_3;

public class Dot {
    private Integer x;
    private Integer y;
    Dot(){
        x = 0;
        y = 0;
    }
    Dot(Integer x, Integer y){
        this.x = x;
        this.y = y;
    }
    public void setX(Integer x){
        this.x = x;
    }
    public void setY(Integer y){
        this.y = y;
    }
    public int getCoordenateX(){
        return x;
    }
    public int getCoordenateY(){
        return y;
    }    
}
