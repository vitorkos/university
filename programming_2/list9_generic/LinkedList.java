public class LinkedList<T> {

    private Nodo<T> primeiro;

    // Construtor para inicializar a lista vazia
    public LinkedList() {
        this.primeiro = null;
    }

    // Método para verificar se a lista está vazia
    public boolean estaVazia() {
        return primeiro == null;
    }

    // Método para adicionar um elemento no início da lista
    public void adicionarInicio(T elemento) {
        Nodo<T> novoNodo = new Nodo<>(elemento);
        novoNodo.setProximo(primeiro);
        primeiro = novoNodo;
    }

    // Método para imprimir os elementos da lista
    public void imprimirLista() {
        Nodo<T> atual = primeiro;

        while (atual != null) {
            System.out.print(atual.getElemento() + " ");
            atual = atual.getProximo();
        }

        System.out.println(); // Adiciona uma quebra de linha no final
    }

    // Classe interna para representar os nodos da lista
    private static class Nodo<T> {
        private T elemento;
        private Nodo<T> proximo;

        // Construtor para criar um nodo com um elemento
        public Nodo(T elemento) {
            this.elemento = elemento;
            this.proximo = null;
        }

        // Métodos getter e setter para o elemento e o próximo nodo
        public T getElemento() {
            return elemento;
        }

        public Nodo<T> getProximo() {
            return proximo;
        }

        public void setProximo(Nodo<T> proximo) {
            this.proximo = proximo;
        }
    }

    public static void main(String[] args) {
        // Testando a lista encadeada com elementos inteiros
        LinkedList<Integer> listaInteiros = new LinkedList<>();
        listaInteiros.adicionarInicio(3);
        listaInteiros.adicionarInicio(7);
        listaInteiros.adicionarInicio(1);

        System.out.print("Lista de inteiros: ");
        listaInteiros.imprimirLista();

        // Testando a lista encadeada com elementos de string
        LinkedList<String> listaStrings = new LinkedList<>();
        listaStrings.adicionarInicio("Hello");
        listaStrings.adicionarInicio("World");

        System.out.print("Lista de strings: ");
        listaStrings.imprimirLista();
    }
}
