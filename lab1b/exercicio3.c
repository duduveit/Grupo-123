#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int num, i, j;

  printf("Digite o numero maximo da piramede.\n");
  scanf("%d", &num);

  if (num % 2 == 0){
     printf("Numero invalido.\n");
     return 1;
  }
    
  for(i = 0; i <= (num / 2) + 1; i++){ //Quantidade de linhas na piramede
    for (j = i + 1; j <= num - i; j++ ) //Imprime os valores
        printf("%d ",j);
    printf("\n");

    for ( j = 0; j < (i+1) * 2; j++ ) 
      printf(" ");
  }
  return 0;
}
