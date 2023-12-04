import java.util.Scanner;
import java.util.Scanner;

public class Questao2 {
    public static void main(String[] args) {
        try (Scanner teclado = new Scanner(System.in)) {
            System.out.println("Eu sei dividir!");
            System.out.print("Digite o numerador: ");
            int numerador = teclado.nextInt();
            System.out.print("Digite o denominador: ");
            int denominador = teclado.nextInt();
            try {
                System.out.println("Resultado: " + numerador / denominador);
            } catch (ArithmeticException e) {
                System.out.println("Erro: divisão por 0" + e);
            }
        }
    }
}
