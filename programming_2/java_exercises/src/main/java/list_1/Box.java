package list_1;

public class Box {
    
    Double width;
    Double height;
    Double lenght;

    Box()
    {
        width = 20.0;
        height = 15.0;
        lenght = 30.0;
    }
    
    Double calculateVolume()
    {
        Double volume = width * height * lenght;
        return volume;
    }
    
}
