//https://home.cs.colorado.edu/~srirams/courses/csci2824-spr14/gmpTutorial.html

#include "gmp.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
  int n, i;

  if (argc <= 1){
    printf ("Rode o arquivo: %s <numero de iteracoes> \n", argv[0]);
    return 0;
  }
  n = atoi(argv[1]);

  // declarando variaveis do tipo mpf_t
  mpf_t euler, aux, fatorial, aux2;
  
  mpf_init2(euler, 100010U);
  mpf_set_ui(euler,1);
  
  mpf_init2(fatorial, 100010U);
  mpf_set_ui(fatorial,1);
  
  mpf_init2(aux, 100010U);
  mpf_set_ui(aux,1);
  
 mpf_init2(aux2, 100010U);
 mpf_set_ui(aux2,1);
  
  for (int i = 1; i <= n; i++) {
      mpf_mul_ui(fatorial, fatorial, i);
      mpf_div(aux, aux2, fatorial);
      mpf_add(euler, euler, aux);
  }

  gmp_printf("%.10000Ff\n", euler);

  mpf_clear(fatorial);
  mpf_clear(aux2);
  mpf_clear(euler);
  mpf_clear(aux);
  return 1;
}
