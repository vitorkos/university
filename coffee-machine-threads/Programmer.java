class Programmer extends Thread {
    private String name;
    private CoffeeMachine coffeeMachine;

    public Programmer(String name, CoffeeMachine coffeeMachine) {
        this.name = name;
        this.coffeeMachine = coffeeMachine;
    }

    @Override
    public void run() {
        coffeeMachine.getCoffee(name);
    }
}