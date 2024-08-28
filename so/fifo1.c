// Arquivo mqrecv.c: recebe mensagens de uma fila de mensagens POSIX.
// Em Linux, compile usando: cc -Wall mqrecv.c -o mqrecv -lrt

#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <sys/stat.h>
#include <fcntl.h> // Para os flags O_RDWR e O_CREAT

#define QUEUE "/my_queue"

int main(int argc, char *argv[])
{
    mqd_t queue; // descritor da fila de mensagens
    struct mq_attr attr; // atributos da fila de mensagens
    int msg; // as mensagens são números inteiros

    // Define os atributos da fila de mensagens
    attr.mq_maxmsg = 10; // capacidade para 10 mensagens
    attr.mq_msgsize = sizeof(msg); // tamanho de cada mensagem
    attr.mq_flags = 0;

    // Abre ou cria a fila com permissões 0666
    if ((queue = mq_open(QUEUE, O_RDWR | O_CREAT, 0666, &attr)) < 0)
    {
        perror("mq_open");
        exit(1);
    }

    // Loop infinito para receber e processar mensagens
    for (;;)
    {
        // Recebe uma mensagem da fila
        if (mq_receive(queue, (char*)&msg, sizeof(msg), NULL) < 0)
        {
            // Caso ocorra um erro ao receber a mensagem, imprime o erro e sai
            perror("mq_receive");
            exit(1);
        }
        // Imprime o valor da mensagem recebida
        printf("Received msg value %d\n", msg);
    }

    // Fecha a fila de mensagens (não alcançável no loop infinito, mas incluído para referência)
    mq_close(queue);
    
    return 0;
}
