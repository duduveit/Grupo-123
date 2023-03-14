#include <stdio.h>

int AcharCaracter(char *Palavra, char Carac){
    for(int a=0;*Palavra!='\0';a++){
        if(*(Palavra+a)==Carac){
            return a+1;
        }
    }
    return 0;
}

int main()
{
    char* palavra="Paralelismo";
    printf("a Palavra %s, possui a caracter %c, na posicao %d\n",palavra,'l',AcharCaracter(palavra,'l'));
    return 0;
}
