/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author geedorah
 */
public class Lamp {

    boolean state;

    Lamp()
    {
        state = false;
    }
    void turnOn()
    {
        state = true;
    }
    void turnOff()
    {
        state = false;
    }
    String stateValue()
    {
        if (state == false)
        {
            return "off";
        }
        else{
            return "on";
            }
    }

    public static void main(String args[]) {
        Lamp lamp = new Lamp();
        System.out.println(lamp.stateValue());
    }
}