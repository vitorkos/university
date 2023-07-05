package list_4_5;

class Main {
    public static void main(String[] args){
        System.out.println("QUERY/ PATIENT EXERCISE");
        Query query = new Query();
        Patient patient = query.getPatient();
        System.out.println("Patient Code: " + patient.getCode());
        System.out.println("Patient Name: " + patient.getName());
        System.out.println("Patient Birthdate: " + patient.getBirthdate().getYear() + "-" +patient.getBirthdate().getMonth() + "-" +patient.getBirthdate().getDay());
        



        System.out.println("CARD EXERCISE");
        
    }
}
