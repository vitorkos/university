package list_1;

class Lamp {
    
    Boolean state;
    
    Lamp()
    {
        state = false;
    }
    
    void turnOn()
    {
        state = true;
    }
    void tunOff()
    {
        state = false;
    }
    String showState()
    {
        if (state == true){
            return "on";
        }
        else{
            return "off";
        }
    }
    
    public static void main(String[] args)
    {
        Lamp lamp = new Lamp();
        
        System.out.println(lamp.showState());
        
        lamp.turnOn();
        
        System.out.println(lamp.showState());
        
    }
}
