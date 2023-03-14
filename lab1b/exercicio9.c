#include <stdio.h>
#include <stdlib.h>

void substituiModulo(int matriz[][3], int LIN, int COL) {
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            if (matriz[i][j] < 0) {
                matriz[i][j] = matriz[i][j] * (-1);
            }
        }
    }
}

int main() {
    int matriz[3][3] = {{8,-5, 4}, {-9, 4, -2}, {6, -7, 3}};

    printf("\nMatriz original:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }

    substituiModulo(matriz, 3, 3);

    printf("\nMatriz em modulo:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
