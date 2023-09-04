package list_7;

public class Teste {
    public static void main(String[] args) {
        IareaCalculavel[] objetos = new IareaCalculavel[5];
        objetos[0] = new Rectangle(10, 20);
        objetos[1] = new Square(10);
        objetos[2] = new Rectangle(20, 30);
        objetos[3] = new Square(20);
        objetos[4] = new Rectangle(30, 40);
        for (int i = 0; i < objetos.length; i++) {
            System.out.println("Area: " + objetos[i].calcularArea());
        }
    }
}
