#include <stdio.h>

typedef struct{
    int idade;
    float peso;
    float altura;
} Pessoa;

void SetPessoa(Pessoa *P, int idade, float peso, float altura){ 
    (*P).idade = idade;
    P->peso = peso;
    P->altura = altura;
}

void ImprimePessoa(Pessoa P)
{
  printf("Idade: %d  Peso: %.1f Altura: %.2f\n", P.idade, P.peso, P.altura);
}

int main() {
    Pessoa pessoas[3];
    char nome[50];
  
    for (int i = 0; i < 3; i++) {
        printf("\nDigite o nome da pessoa %d: ", i+1);
        scanf("%s", nome);
    }

    SetPessoa(&pessoas[0], 20, 85, 1.80);
    SetPessoa(&pessoas[1], 21, 90, 1.90);
    SetPessoa(&pessoas[2], 22, 95, 1.70);

    printf("\n\nDados das pessoas:\n");
    for (int i = 0; i < 3; i++) {
        printf("Pessoa %d -> ", i+1);
        ImprimePessoa(pessoas[i]);
        printf("\n");
    }

    return 0;
}
