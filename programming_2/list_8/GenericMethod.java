package list_8;

public class GenericMethod {
    
    public static somar(T[] array) {
        T soma = 0;
        for (T elemento : array) {
            soma += elemento;
        }
        System.out.println(soma);
    }
}
