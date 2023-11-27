package list_4_5;

import java.time.LocalDate;

class Query {
    private Patient patient;

    Query(){
        patient = new Patient(121, "Vitor", LocalDate.of(1990, 6, 15));
    }

    public Patient getPatient(){
        return patient;
    }
}
