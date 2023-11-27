package list_7;

public class Rectangle implements IareaCalculavel{
    double width, height;
    Rectangle(){
        width = 0.0; height = 0.0;
    }
    Rectangle(double w, double h){
        width = w; height = h;
    }
    @Override
    public double calcularArea() {
        return width * height;
    }
}