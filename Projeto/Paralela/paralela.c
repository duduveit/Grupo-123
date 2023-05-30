#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// Resultado global do euler
mpf_t global_result;

// Número de iterações
int iteracoes;

void Euler();

int main(int argc , char*argv[]) {
  if (argc <= 1){
    printf ("Rode o arquivo: %s <numero de iteracoes> \n", argv[0]);
    return 0;
  }
  
  iteracoes = atoi(argv[1]);
  int thread_count = 2;
    
  mpf_init2(global_result, 100000U);
  mpf_set_ui(global_result, 1);
  
# pragma omp parallel num_threads(thread_count)

  Euler();
  gmp_printf("%.10000Ff\n", global_result);
  
  mpf_clear(global_result);
  return 0;
}

void Euler(){
  int i;

  mpf_t soma_local, divisao, fatorial;
  
  mpf_init2(soma_local, 1000000U);
  mpf_set_ui(soma_local, 0);

  mpf_init2(divisao, 1000000U);
  mpf_set_ui(divisao, 0);

  mpf_init2(fatorial, 1000000U);
  mpf_set_ui(fatorial,1);
  
  int my_rank = omp_get_thread_num();
  int thread_count = omp_get_num_threads();

  int div = iteracoes/thread_count;
  int inicio = (my_rank * div) + 1;
  int fim = (my_rank+1) * div;

  if(my_rank >= 1){
    i = 1;
    while (i<=inicio-1){
      mpf_mul_ui(fatorial, fatorial,i);
      i++;
    }
  }
  for (i = inicio; i<=fim; i++){;
    mpf_mul_ui(fatorial, fatorial,i);
    mpf_ui_div(divisao, 1, fatorial);
    mpf_add(soma_local, soma_local, divisao);
  }
 
 # pragma omp critical
  mpf_add(global_result, global_result, soma_local);

  mpf_clear(soma_local);
  mpf_clear(divisao);
  mpf_clear(fatorial);
}
