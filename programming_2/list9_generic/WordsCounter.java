import java.util.HashMap;
import java.util.Map;

public class WordsCounter {
    public static void main(String[] args) {
        String texto = "O vento varria as folhas\nO vento varria os frutos";
        // Converter o texto para minúsculas
        texto = texto.toLowerCase();
        // Dividir o texto em palavras
        String[] palavras = texto.split("\\s+"); // \\s+ significa um ou mais espaços em branco
        // Usar um Map para armazenar a contagem de cada palavra
        Map<String, Integer> frequenciaPalavras = new HashMap<>();
        // Contar a frequência de cada palavra
        for (String palavra : palavras) {
            // Remover pontuações se necessário
            palavra = palavra.replaceAll("[^a-zA-Z]", "");
            // Atualizar a contagem no mapa
            frequenciaPalavras.put(palavra, frequenciaPalavras.getOrDefault(palavra, 0) + 1);
        }
        // Exibir a contagem de frequência de cada palavra
        for (Map.Entry<String, Integer> entry : frequenciaPalavras.entrySet()) {
            System.out.println(entry.getKey() + " → " + entry.getValue());
        }
    }
}
