#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main() {
	int shmid;
	int size = 1024;
	char *path = "./";
	int *ptr;
   	int value = 1;
    	pid_t pid;

	#define ADDKEY 123

	if (( shmid = shmget(ftok(path,ADDKEY), size, IPC_CREAT | IPC_EXCL|SHM_R|SHM_W)) == -1) {
		perror("Erro no shmget") ;
		exit(1) ;
	}

	// Anexa o processo pai ao segmento de memória compartilhad
	ptr = (int*) shmat(shmid, NULL, 0);
        
	// Atribui a variável value no segmento de memória compartilhada
    	*ptr = value;

    	// Imprime o valor inicial da variável antes de criar o processo fiho
    	printf("Valor inicial da variável compartilhada: %d\n", *ptr);

	// Cria um processo filho
    	pid = fork();
    	if (pid < 0) {
        	perror("Erro no Fork");
        	exit(1);
	}

	// Processo filho
    	if (pid == 0) {
		*ptr  += 2;

        	// Desanexa o segmento de memória compartilhada do espaço de endereçamento do processo filho
        	shmdt(ptr);
        	exit(0);
  	 }

	// Processo pai
	 else {
	        printf("Processo pai: esperando processo filho terminar...\n");
        	wait(NULL);

                *ptr *= 4;

       		 // Imprime o valor final da variável compartilhada
        	printf("Valor da variável compartilhada depois do processo filho: %d\n", *ptr);

        	// Desanexa o segmento de memória compartilhada do espaço de endereçamento do processo pai
        	shmdt(ptr);

       		 // Libera o segmento de memória compartilhada
        	if ((shmctl(shmid, IPC_RMID, NULL)) == -1){
			perror("Erro shmctl()");
 			exit(1);
		}
 		exit(0);;
    }

    return 0;
}
