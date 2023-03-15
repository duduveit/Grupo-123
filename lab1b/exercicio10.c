#include <stdio.h>

void multiplicaLinha(int matriz[][3], int LIN, int COL, int valor) {
    for (int j = 0; j < COL; j++) {
        matriz[LIN][j] *= valor;
    }
}

void multiplicaColuna(int matriz[][3], int COL, int LIN, int valor) {
    for (int i = 0; i < LIN; i++) {
        matriz[i][COL] *= valor;
    }
}

void imprimeMatriz(int matriz[][3], int LIN, int COL) {
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matriz[3][3] = {{8, 5, 4}, {9, 4, 2}, {6, 7, 3}};

    printf("\nMatriz original:\n");
    imprimeMatriz(matriz, 3, 3);

    multiplicaLinha(matriz, 1, 3, 2);
    printf("\nMultiplicando linha 2 por 2:\n");
    imprimeMatriz(matriz, 3, 3);

    multiplicaColuna(matriz, 2, 3, 3);
    printf("\nMultiplicando coluna 3 por 2:\n");
    imprimeMatriz(matriz, 3, 3);

    return 0;
}
