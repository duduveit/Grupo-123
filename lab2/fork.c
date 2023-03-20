#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    int pid = fork();
    if (pid < 0){
       printf("Fork Failed\n");
       exit(-1);
    }
    else if(pid == 0){
       //Processo filho calculará a primeira metada da mmultiplicação
       int result = 1;
       for(int i = 1; i <= n/2; i++)
          result *= i;
       //Resultado passará a ser o valor de confirmação do término do processo filho
       exit(result);
    }
    else {
       // processo pai calcula o fatorial parcial de n - (n/2)
       int result = 1;
       for(int i = n/2 + 1; i <= n; i++)
           result *= i;
       // espera o processo filho terminar e obtém o resultado parcial do fatorial
       int status;
       wait(&status);
       result *= WEXITSTATUS(status);

       printf("%d! = %d\n", n, result);
       exit(0);
       }
       return 0;
}
