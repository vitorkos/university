public class Main {
    public static void main(String[] args) {
        CoffeeMachine coffeeMachine = new CoffeeMachine();
        
        // Criando e iniciando múltiplas threads para simular os programadores
        Programmer[] programmers = new Programmer[5];
        for (int i = 0; i < programmers.length; i++) {
            programmers[i] = new Programmer("Programador " + (i + 1), coffeeMachine);
            programmers[i].start();
        }
    }
}