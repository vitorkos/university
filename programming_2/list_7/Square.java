package list_7;

public class Square implements IareaCalculavel {
    double side;
    Square(){
        side = 0.0;
    }
    Square(double s){
        side = s;
    }
    @Override
    public double calcularArea() {
        return side * side;
    }

}
