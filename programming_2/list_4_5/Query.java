package list_4_5;

class Query {
    private Patient patient;
    Query(){
        patient = new Patient(121, "vitor", patient.getBirthdate());        
    }
    public Patient getPatient(){
        return patient;
    }
}
