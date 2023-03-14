#include <stdio.h>
#include <string.h>

int main(void)
{
  char nome1[21], nome2[21];
  
  printf("Digite o primeiro nome: ");
  scanf("%s",nome1);

  printf("Digite o segundo nome: ");
  scanf("%s",nome2);  

  
  printf("Ordem alfabética dos nomes:\n");
  if (strcmp(nome1, nome2) < 0) 
    printf("%s\n%s\n", nome1, nome2);
  else
    printf("%s\n%s\n", nome2, nome1);
  return 0;
}
