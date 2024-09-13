#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main()
{
    pid_t pid;

    // Crear un proceso hijo
    pid = fork();

    if (pid < 0)
    {
        // Error al crear el proceso
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        // Este es el proceso hijo
        printf("Proceso hijo con PID %d creado.\n", getpid());
        // El proceso hijo termina aquí
        exit(EXIT_SUCCESS);
    }
    else
    {
        // Este es el proceso padre
        printf("Proceso padre con PID %d.\n", getpid());
        // Espera para que el proceso hijo se convierta en zombie
        printf("Esperando 60 segundos para que el proceso hijo se convierta en zombie...\n");
        sleep(60);

        // Opcional: Verificar el estado del proceso hijo
        printf("Proceso padre con PID %d ha terminado la espera.\n", getpid());
        printf("Verifica el estado del proceso hijo con el comando `ps -l`.\n");
    }

    return 0;
}
