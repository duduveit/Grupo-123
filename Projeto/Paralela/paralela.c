#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void Euler(int n, long double* global_result_p);
long double fatorial(int n);

int main(int agrc , char*argv[]){
    long double global_result = 1;
    int n = 20;
    int thread_count;

    thread_count = strtol(argv[1],NULL, 10);

#pragma omp parallel num_threads(thread_count)
    Euler(n, &global_result);
    printf("Euler=%0.62Lf\n", global_result);
    return 0;
}

void Euler(int n,long double* global_result_p){
    long double soma_local = 0;

    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();

    int div = n/thread_count;
    int inicio = my_rank * div + 1;
    int fim;

    if(my_rank == thread_count-1){
        fim = n;
    } else {
        fim = inicio + div - 1;
    }

    for (int a = inicio; a<=fim; a++) 
        soma_local += 1/fatorial(a);

#pragma omp critical
    *global_result_p += soma_local;
}

long double fatorial(int n){
    if(n==0){
        return 1;
    } else{
        return n*fatorial(n-1);
    } 
}
