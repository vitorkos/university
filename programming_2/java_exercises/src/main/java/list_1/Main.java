package list_1;

public class Main{
    public static void main(String[] args) {
        
        System.out.println("-Lamp-");
        Lamp lamp = new Lamp();
        
        System.out.println(lamp.showState());
        
        lamp.turnOn();
        
        System.out.println(lamp.showState());
        
        System.out.println("-Box-");
        Box box = new Box();
                
        System.out.println(box.calculateVolume());
        
        System.out.println("-Date-");
        Date date = new Date(18, 4, 2023);
        
        System.out.println(date.formatDate('-'));
    }
}
