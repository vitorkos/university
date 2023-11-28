import java.util.ArrayList;
import java.util.Collection;

public class BiggerElementGeneric {

    public static <T extends Comparable<T>> T encontrarMaiorElemento(Collection<T> colecao) {
        if (colecao == null || colecao.isEmpty()) {
            throw new IllegalArgumentException("A coleção não pode ser nula ou vazia.");
        }

        T maiorElemento = null;

        for (T elemento : colecao) {
            if (maiorElemento == null || elemento.compareTo(maiorElemento) > 0) {
                maiorElemento = elemento;
            }
        }

        return maiorElemento;
    }

    public static void main(String[] args) {
        // Testando o método com uma coleção de Integers
        ArrayList<Integer> numeros = new ArrayList<>();
        numeros.add(10);
        numeros.add(5);
        numeros.add(8);

        Integer maiorNumero = encontrarMaiorElemento(numeros);
        System.out.println("Maior número: " + maiorNumero);

        // Testando o método com uma coleção de Strings
        ArrayList<String> palavras = new ArrayList<>();
        palavras.add("banana");
        palavras.add("abacaxi");
        palavras.add("maçã");

        String maiorPalavra = encontrarMaiorElemento(palavras);
        System.out.println("Maior palavra: " + maiorPalavra);
    }
}