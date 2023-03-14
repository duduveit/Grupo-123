#include <stdio.h>
#include <stdlib.h>

int veririca(int **mat, int LIN){
  int menor = mat[0][0];
  int linha = 0;
  for(int i = 0; i < LIN; i++) {
    for(int j = 0; j < LIN; j++) {
      if(mat[i][j] < menor) {
        menor = mat[i][j];
        linha = i;
        }
      }
    }
  return linha;
}
void ImprimeMatriz(int **mat, int LIN){ 
  printf ("\nMatriz %d X %d: \n", LIN, LIN);
  for(int i = 0; i < LIN; i++){
    for(int j = 0; j < LIN; j++){
      printf("%2d ", mat[i][j]);
    }
    printf("\n");
  }
}
void LiberaAlocacao(int **mat, int LIN){
  for (int i=0; i < LIN; i++)
    free (mat[i]);
  free (mat) ;
}

int main(){
  
  int LIN;
  printf("Digite o numero de linhas da matriz quadrada: ");
  scanf("%d", &LIN);
  
  int **mat;
  int i, j;
  
  // Aloca a matriz de celulas
  mat = malloc (LIN * sizeof (int*));
  for (i=0; i < LIN; i++)
    mat[i] = malloc (LIN * sizeof (int));
  
  // Preenche o conteúdo da matriz com numeros aleatórios de 0 a 99
  for (i=0; i < LIN; i++)
    for (j=0; j < LIN; j++)
      mat[i][j] = rand() % 100;;

  int result = veririca(mat, LIN);
  ImprimeMatriz(mat, LIN);
  printf("\nA linha com o menor valor é %d\n", result);
  LiberaAlocacao(mat, LIN);
}
