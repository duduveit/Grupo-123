#include <stdio.h>
#include <stdlib.h>

void PreencheMatriz(int **mat, int LIN, int COL){
  int i, j, elemento;
  for (i = 0; i < LIN; i++) {
    for (int j = 0; j < COL; j++) {
      printf("Digite o valor do elemento da matriz[%d][%d]: ", i, j);
      scanf("%d", &elemento);
      mat[i][j] = elemento;
    }
  }
}

void ImprimeMatriz(int **mat, int LIN, int COL){ 
  printf ("\nMatriz %d X %d: \n", LIN, COL);
  for(int i = 0; i < LIN; i++){
    for(int j = 0; j <  COL; j++){
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

void multLinha(int **mat, int COL, int linha, int valor){
  for (int i = 0; i < COL; i++)
    mat[linha][i] *= valor;
}

void multColuna(int **mat, int LIN, int coluna, int valor){
  for (int i = 0; i < LIN; i++)
    mat[i][coluna] *= valor;
}

int main(){
  
  int LIN, COL;
  printf("Digite o numero de linhas da matriz: ");
  scanf("%d", &LIN);

  printf("Digite o numero de colunas da matriz: ");
  scanf("%d", &COL);
  
  int **mat;
  int i, j, valor, linha, coluna;

  // Aloca a matriz de celulas
  mat = (int **) malloc(LIN * sizeof(int *));
  for (int i = 0; i < LIN; i++)
    mat[i] = (int *) malloc(COL * sizeof(int));
  
  PreencheMatriz(mat, LIN, COL);  
  ImprimeMatriz(mat, LIN, COL);
  
  printf("Valor que multiplicará na matriz: ");
  scanf("%d", &valor);
  
  printf("Digite a linha em que os valores serão multiplicados: ");
  scanf("%d", &linha);
  multLinha(mat, COL, linha, valor);
  printf("Nova matriz:\n\n");
  ImprimeMatriz(mat, LIN, COL);

  printf("Digite a coluna em que os valores serão multiplicados: ");
  scanf("%d", &coluna);
  multColuna(mat, LIN, coluna, valor);
  printf("Nova matriz:\n\n");
  ImprimeMatriz(mat, LIN, COL);
  
  LiberaAlocacao(mat, LIN);
}
