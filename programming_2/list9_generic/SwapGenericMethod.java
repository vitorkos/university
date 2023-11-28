import java.util.Arrays;

public class SwapGenericMethod {
    public static <T> void swap(T v[], int i, int j){
        T aux = v[i];
        v[i] = v[j];
        v[j] = aux;
    }
    public static void main(String[] args) {
        Integer[] arrayInteiros = {1, 2, 3, 4, 5};
        System.out.println("Array antes da troca: " + Arrays.toString(arrayInteiros));

        swap(arrayInteiros, 1, 3);

        System.out.println("Array após a troca: " + Arrays.toString(arrayInteiros));

        // Testando o método com um array de strings
        String[] arrayStrings = {"A", "B", "C", "D", "E"};
        System.out.println("Array antes da troca: " + Arrays.toString(arrayStrings));

        swap(arrayStrings, 0, 4);

        System.out.println("Array após a troca: " + Arrays.toString(arrayStrings));
    }
}
