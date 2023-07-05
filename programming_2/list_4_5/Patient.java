package list_4_5;
class Patient {
    private Integer code;
    private String name;
    private Date birth_date;
    Patient(){
        code = 0;
        name = "";
        birth_date = new Date();
    }
    Patient(Integer code, String name, Date birth_date){
        this.code = code;
        this.name = name;
        this.birth_date = birth_date;
    }
    public Integer getCode() {
        return code;
    }
    
    public String getName() {
        return name;
    }
    
    public Date getBirthdate() {
        return birth_date;
    }
}
