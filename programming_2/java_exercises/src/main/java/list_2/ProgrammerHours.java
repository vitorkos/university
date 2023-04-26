package list_2;

public class ProgrammerHours {
    
    Double value_hour;
    Double worked_hour;

    ProgrammerHours()
    
    {
        value_hour = 0.0;
        worked_hour = 0.0;
    }

    ProgrammerHours(Double value_hour, Double worked_hour)
    {
        this.value_hour = value_hour;
        this.worked_hour = worked_hour;
    }
    Double calculateSalary()
    {
        Double salary = value_hour * worked_hour;
        return salary;
    }    
}
