package list_4_5;

import java.time.LocalDate;

class Patient {
    private Integer code;
    private String name;
    private LocalDate birth_date;

    Patient(){
        code = 0;
        name = "";
        birth_date = null;

    }
    Patient(Integer code, String name, LocalDate birth_date){
        this.code = code;
        this.name = name;
        this.birth_date = birth_date;
    }
    public void setCode(Integer n){
        code = n;
    }
    public void setName(String nam){
        name = nam;
    }
    public void setBirthdate(LocalDate bd){
        birth_date = bd;
    }
    public Integer getCode() {
        return code;
    }    
    public String getName() {
        return name;
    }
    public LocalDate getBirthdate(){
        return birth_date;
    }
}
