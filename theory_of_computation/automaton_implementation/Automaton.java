//Declarando a classe do automato
public class Automaton{
    //Definindo as constantes dos estados do automato
    private static final int INITIALSTATE = 0;
    private static final int INTERMEDIATESTATE = 1;
    private static final int FINALSTATE = 2;

    public static boolean validateInput(String input){
        int actualState = INITIALSTATE;
        //for each 'c' from input ; toCharArray turns a char string to a array
        for (char c : input.toCharArray()){
            actualState = transition(actualState, c);
            if(actualState == -1){
                return false;
            }
        }
    return actualState == FINALSTATE;
    }

    public static int transition(int actualState, char simbol){
        switch(actualState){

            case 0: //initial state
                if(simbol == 'a'){
                    return INTERMEDIATESTATE;
                }
                else{
                    return 0; // stay in inital state
                }

            case 1: //intermediate state
            if(simbol == 'a'){
                return FINALSTATE;
            }
            else if(simbol == 'b'){
                return 1; //continues in intermediate state
            }
            else{
                return 0; //goes back to initial state
            }

            case 2: //final state
                return 2; //continues in final state
            default:
                return -1; //invalid state
        }
    }

    public static void main(String[] args){
        String input = "abcbaabxyz";

        if(validateInput(input)){
            System.out.println("Valid");
        }
        else{
            System.out.println("Invalid");
        }
    }
}
