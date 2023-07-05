package list_4_5;

class Main {
    public static void main(String[] args){
        System.out.println("QUERY/ PATIENT EXERCISE");
        Query query = new Query();
        Patient patient = query.getPatient();
        System.out.println("Patient Code: " + patient.getCode());
        System.out.println("Patient Name: " + patient.getName());
        
        System.out.println("CARD EXERCISE");
        Card card = new Card();
        card.useCredit();
        System.out.println(card.getBalance());
        card.load(5);
        System.out.println(card.getBalance());
    }
}
