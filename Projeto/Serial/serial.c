#include <stdio.h>

long double fatorial(int n){
  if(n==0){
    return 1;
  }
  else{
    return n*fatorial(n-1);
  } 
}

int main(void){
  int n=20;
  long double euler= 100.0f;
  euler=1;
  for(int a = 0; a<n; a++){
  	euler += 1/fatorial(a+1);;
  }
  printf("\n\nEuler=%0.62Lf\n",euler); 
  //printf("Euler=2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274");
  return 0;
}
