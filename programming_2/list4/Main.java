package list_4;
class Main {
    public static void main(String args[]) {
        System.out.println("DOG EXERCISE");
        Dog dog = new Dog("cachorro", "viralata");
        
        dog.repeatedBark(100);

        System.out.println("CONTAINER EXERCISE");
        Container container = new Container(10.0, false);
        
        if(container.toOccupy(1.0) == true){
            System.out.println("AAA");
        }
        else{
            System.out.println("BBB");
        }
        System.out.println("GASOLINE PUMP EXERCISE ");
        Gaspump gas = new Gaspump();
        
        gas.supplybyLiter(20.0);
        System.out.println(gas.status());
        
        System.out.println("UTIL EXERCISE");
        System.out.println(Util.isOdd(2));
        
        System.out.println("VARARGS + UTIL EXERCISE");
        System.out.println(Util.bigger(2,3,4,5,6,3));
        
    }
}
