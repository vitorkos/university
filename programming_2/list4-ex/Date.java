package list_4_5;

class Date{
    private Integer year;
    private Integer month;
    private Integer day;
    Date(){
        year = 0;
        month = 0;
        day = 0;
    }
    Date(Integer year, Integer month, Integer day){
        this.year = year;
        this.month = month;
        this.day = day;
    }
    public Integer getYear(){
        return year;
    }
    public Integer getMonth(){
        return month;
    }
    public Integer getDay(){
    return day;
    }

    public void changeDate(Date date, Integer y){
        date.year = y;
    }
    public void changeDate(Date date, Integer y, Integer m){
        date.year = y;
        date.month = m;
    }
    public void changeDate(Date date, Integer y, Integer m, Integer d){
        date.year = y;
        date.month = m;
        date.day = d;
    }
}