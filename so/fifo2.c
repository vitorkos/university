// Arquivo mqsend.c: envia mensagens para uma fila de mensagens POSIX.
// Em Linux, compile usando: cc -Wall mqsend.c -o mqsend -lrt

#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <unistd.h>
#include <fcntl.h> // Para os flags O_RDWR

#define QUEUE "/my_queue"

int main(int argc, char *argv[])
{
    mqd_t queue; // descritor da fila
    int msg; // mensagem a enviar

    // Abre a fila de mensagens, se existir
    if ((queue = mq_open(QUEUE, O_RDWR)) < 0)
    {
        perror("mq_open");
        exit(1);
    }

    // Loop infinito para enviar mensagens
    for (;;)
    {
        // Gera um valor aleatório entre 0 e 99 para a mensagem
        msg = random() % 100;

        // Envia a mensagem para a fila
        if (mq_send(queue, (char*)&msg, sizeof(msg), 0) < 0)
        {
            // Caso ocorra um erro ao enviar a mensagem, imprime o erro e sai
            perror("mq_send");
            exit(1);
        }
        // Imprime o valor da mensagem enviada
        printf("Sent message with value %d\n", msg);
        
        // Espera 1 segundo antes de enviar a próxima mensagem
        sleep(1);
    }

    // Fecha a fila de mensagens (não alcançável no loop infinito, mas incluído para referência)
    mq_close(queue);

    return 0;
}
