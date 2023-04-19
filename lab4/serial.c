#include <stdio.h>
#include <stdlib.h>

int **matrizA;
int *matrizB;
int *matrizResultado;

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

int main(int argc, char* argv[]){
  int m, n;
  int i, j;

  if (argc < 3){
    printf("Erro: informe as dimensoes da matriz e do vetor.\nExecute o código como ./main linha coluna.\n");
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

  //Cálculo da mult de matrizes
  for (i=0; i < m; i++){
    for(j=0; j<n; j++){
      matrizResultado[i] += matrizA[i][j] * matrizB[j];
    }
  }
  
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
