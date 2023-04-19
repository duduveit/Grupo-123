#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int **matrizA;
int *matrizB;
int *matrizResultado;
int m, n; //Linha e coluna
int thread_count; //Número de thread

void imprimirMatriz(int **matriz, int linhas, int colunas) {
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++)
      printf("%d ", matriz[i][j]);
    printf("\n");
  }
}

void imprimirVetor(int *matriz, int linhas){
  for (int i = 0; i < linhas; i++)
    printf("%d\n", matriz[i]);
}

void *multMatrizes(void * rank){
  long my_rank = (long) rank;
  int i, j;
  int local_m = m/thread_count;
  int my_first_row = my_rank*local_m; 
  int my_last_row = (my_rank+1)*local_m-1;

  //printf("Hello from thread %ld of %d\n", my_rank, thread_count);

  for(i = my_first_row; i <= my_last_row; i++){
    matrizResultado[i] = 0.0;
    for(j =0; j < n; j++)
      matrizResultado[i] += matrizA[i][j] * matrizB[j];
  }
  return NULL;
}

int main(int argc, char* argv[]){
  int i, j;

  if (argc < 4){
    printf("Erro: informe as dimensoes da matriz e do vetor e o número de threads.\n");
    return 1;
  }
  m = atoi(argv[1]); //Númmero de linhas
  n = atoi(argv[2]); //Número de colunas
  
  //Aloca matriz
  matrizA = (int **) calloc(m, sizeof(int *));
  for(i = 0; i < m; i++) matrizA[i] = (int *) calloc(n, sizeof(int));
  matrizB = (int *) calloc(n, sizeof(int));
  matrizResultado = (int *) calloc(m, sizeof(int));

  //Preenche matrizes
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) matrizA[i][j] = i+j;
  }
  for (i = 0; i < n; i++) matrizB[i] = (i+1)*2;


  //Iniciando threads
  long thread;
  pthread_t* thread_handles;
  
  thread_count = strtol(argv[3], NULL, 10); //Número de threads

  thread_handles = malloc(thread_count * sizeof(pthread_t));
    
  for (thread = 0; thread < thread_count; thread++)
    pthread_create(&thread_handles[thread], NULL, multMatrizes, (void*)thread);

  for (thread = 0; thread < thread_count; thread++)
    pthread_join(thread_handles[thread], NULL);

  free(thread_handles);
  
  // Imprime resultado
  printf("\nMatriz A\n");
  imprimirMatriz(matrizA, m, n);

  printf("\nMatriz B\n");
  imprimirVetor(matrizB, n);
  
  printf("\nMatriz Resultado\n");
  imprimirVetor(matrizResultado, m);


  // libera memória alocada
  for (i = 0; i < m; i++)
    free(matrizA[i]);

  free(matrizA);
  free(matrizB);
  free(matrizResultado);
  return 0;
}
