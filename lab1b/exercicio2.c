#include <stdio.h>
#include <stdlib.h>

int main(){
  float n1, n2, n3, me, ma;
  printf("Digite a ma 1: ");
  scanf("%f", &n1);
  printf("Digite a ma 2: ");
  scanf("%f", &n2);
  printf("Digite a ma 3: ");
  scanf("%f", &n3);
  printf("Digite a média das atividades: ");
  scanf("%f", &me);

  ma = (n1+n2*2+n3*3+me)/7;

  if (ma >= 9.0) 
    printf("Média de aproveitamento = %.2f -> A\n", ma);
  else if (ma >= 7.5 && ma < 9.0)
    printf("Média de aproveitamento = %.2f -> B\n", ma);
  else if (ma >= 6.0 && ma < 7.5)
    printf("Média de aproveitamento = %.2f -> C\n", ma);
  else if (ma >= 4.0 && ma < 6.0)
    printf("Média de aproveitamento = %.2f -> D\n", ma);
  else 
    printf("Média de aproveitamento = %.2f -> E\n", ma);

    return 0;
}
