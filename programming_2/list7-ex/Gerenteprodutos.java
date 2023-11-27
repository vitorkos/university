package list_7;

public class Gerenteprodutos {
    public static String[] obterIngredientes(String nomeProduto) {
        if (nomeProduto.equals("ProdutoFabricadoA")) {
            return new String[] {"Ingrediente1", "Ingrediente2"};
        }
        return null;
    }

    public static double obterValorCompra(String nomeProduto) {
        // Implemente a lógica para obter o valor de compra com base no nome do produto
        // Exemplo simplificado:
        if (nomeProduto.equals("ProdutoCompradoA")) {
            return 50.0;
        }
        return 0.0;
    }
}
