

class CoffeeMachine {
    // Método sincronizado para simular a retirada de café
    public synchronized void getCoffee(String programmerName) {
        System.out.println(programmerName + " está retirando café.");
        try {
            // Simulando o tempo que leva para retirar o café
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println(programmerName + " terminou de retirar o café.");
    }
}