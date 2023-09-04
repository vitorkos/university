package list_7;

public class Main {
    public static void main(String[] args) {
        Rectangle r = new Rectangle(10, 20);
        Square s = new Square(20);
        System.out.println("Rectangle area: " + r.calcularArea());
        System.out.println("Square area: " + s.calcularArea());
    }
}
