#include <stdio.h>

void SomarLinhas(int i1, int i2, int tamanho,int m[][tamanho]){
    for(int x=0;x<tamanho;x++){
        m[x][i2]=m[x][i2]+m[x][i1];
    }
}
void MultLinhas(int i1, int i2, int tamanho,int m[][tamanho]){
    for(int x=0;x<tamanho;x++){
        m[x][i2]=m[x][i2]*m[x][i1];
    }
}

int main()
{
    int matriz[10][10];
    for(int b=0;b<10;b++){
        for(int a=0;a<10;a++){
            matriz[a][b]=a+b+2;
        }
    }
    for(int b=0;b<10;b++){
        for(int a=0;a<10;a++){
            printf("%2d |", matriz[a][b]);
        }
        printf("\n");
    }
    printf("\nSomar Linhas\n Linha L1=%d\n linha L2=%d\n",0,1);
    SomarLinhas(0,1,10,matriz);
    for(int b=0;b<10;b++){
        for(int a=0;a<10;a++){
            printf("%3d |", matriz[a][b]);
        }
        printf("\n");
    }
    
    printf("\nMultiplicar Linhas\n Linha L1=%d\n linha L2=%d\n",0,1);
    MultLinhas(0,1,10,matriz);
    for(int b=0;b<10;b++){
        for(int a=0;a<10;a++){
            printf("%3d |", matriz[a][b]);
        }
        printf("\n");
    }
    return 0;
}
