import java.util.HashMap;
import java.util.Map;

public class GenericStudents {
    public static void main(String[] args) {
        Map<Integer, String> studentsList = new HashMap<>();
        
        adicionarAluno(studentsList, 101, "João Silva");
        adicionarAluno(studentsList, 102, "Maria Oliveira");
        adicionarAluno(studentsList, 103, "Carlos Santos");

        // Exibindo a lista de alunos
        System.out.println("Lista de Alunos:");
        exibirListaDeAlunos(studentsList);
    }

    // Método para adicionar um aluno à lista
    private static void adicionarAluno(Map<Integer, String> listaDeAlunos, int matricula, String nome) {
        listaDeAlunos.put(matricula, nome);
    }

    // Método para exibir a lista de alunos
    private static void exibirListaDeAlunos(Map<Integer, String> listaDeAlunos) {
        for (Map.Entry<Integer, String> entry : listaDeAlunos.entrySet()) {
            System.out.println("Matrícula: " + entry.getKey() + ", Nome: " + entry.getValue());
        }
    }
}
