/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */

/**
 *
 * @author geedorah
 */
public class Box {

    double lenght;
    double height;
    double width;
    
    Box()
    {
        lenght = 20;
        height = 15;
        width = 20;
    }
    
    double calculateVolume()
    {
        double volume = lenght * height * width;
        
        return volume;
    }
    
    public static void main(String args[]) {
        Box box = new Box();
        System.out.println(box.calculateVolume());
    }
}
