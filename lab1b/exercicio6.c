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

void PreencheTransposta(int **mat, int **trans, int LIN, int COL){
  int i,j;
  for (i = 0; i<LIN; i++){
    for (j=0; j<COL; j++)
      trans[j][i] = mat[i][j];
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

int main(){
  
  int LIN, COL;
  printf("Digite o numero de linhas da matriz: ");
  scanf("%d", &LIN);

  printf("Digite o numero de colunas da matriz: ");
  scanf("%d", &COL);
  
  int **mat, **trans;
  int i, j, valor, linha, coluna;

  // Aloca a matriz de celulas
  mat = (int **) malloc(LIN * sizeof(int *));
  for (i = 0; i < LIN; i++)
    mat[i] = (int *) malloc(COL * sizeof(int));
  
  PreencheMatriz(mat, LIN, COL);
  printf("\nNormal");
  ImprimeMatriz(mat, LIN, COL);

  //Aloca a matriz de celulas da matriz composta
  trans = (int**) malloc(COL * sizeof(int *));
  for (i=0; i<COL; i++)
    trans[i] = (int *) malloc(LIN * sizeof(int));

  PreencheTransposta(mat, trans, LIN, COL);
  printf("\nTransposta");
  ImprimeMatriz(trans, COL, LIN);
  LiberaAlocacao(mat, LIN);
  LiberaAlocacao(trans, COL);
  return 0;
}

