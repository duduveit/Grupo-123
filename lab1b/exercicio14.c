#include <stdio.h>

int StringSize(char* Str){
	int a=0;
	while(Str[a]!='\0'){
		a++;
	}
	return a;
}

void InserePosicao(char* Str, int x,char Carac){
	int Size=StringSize(Str);
    for(int a=Size;a>=x;a--){
    	Str[a+1]=Str[a];
	}
	Str[x]=Carac;

}

int main()
{
    char Str[100]="Paralelismo";
    printf("%s\n",Str);
    InserePosicao(Str,4,'!');
    printf("a Palavra %s, possui a caracter %c, na posicao %d\n",Str,'!',4);
    return 0;
}
