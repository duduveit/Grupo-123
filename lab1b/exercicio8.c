#include <stdio.h>
#include <stdlib.h>

void criaTransposta(int matriz[][3], int LIN, int COL) {
    int **novaMatriz = (int **) malloc(COL * sizeof(int *));
    for (int i = 0; i < COL; i++) {
        novaMatriz[i] = (int *) malloc(LIN * sizeof(int));
    }
    
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            novaMatriz[j][i] = matriz[i][j];
        }
    }

    printf("\nMatriz transposta:\n");
    for (int i = 0; i < COL; i++) {
        for (int j = 0; j < LIN; j++) {
            printf("%d ", novaMatriz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < COL; i++) {
        free(novaMatriz[i]);
    }
    free(novaMatriz);
}

int main() {
    int matriz[2][3] = {{8, 6, 3}, {1, 7, 2}};
  
    printf("\nMatriz original:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
  
    criaTransposta(matriz, 2, 3);
    return 0;
}
