package list_2;

class Car {
    
    String brand;
    String model;
    Integer year;
    Integer speed;

    Car()
    {
        brand = "";
        model = "";
        year = 0;
        speed = 0;
    }
    
    Car (String brand, String model, Integer year, Integer speed)
    {
        this.brand = brand;
        this.model = model;
        this.year = year;
        this.speed = speed;
    }
    
    void accelerate()
    {
        speed += 10;
    }
    void brake()
    {
        speed -= 10;
    }
}

