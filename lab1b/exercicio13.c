#include <stdio.h>

char RemovePosicao(char* Str, int x){
    char Removido=*(Str+x);
    x--;
    for(int a=0;*(Str+a)!='\0';a++){
        if(a>x){
        *(Str+a)=*(Str+a+1);
        }
    }
    return Removido;
}


int main()
{
    char Str[100]="Paralelismo";
    printf("%s\n",Str);
    char Removido=RemovePosicao(Str,0);
    printf("foi Removido %c, na posição %d, e a palavra ficou %s\n", Removido,0, Str);

    return 0;
}
