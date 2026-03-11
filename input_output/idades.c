#include <stdio.h>
#include <math.h>

int main(){

    char nome1[50], nome2[50]; //String é um vetor de char
    int idade1, idade2;
    double media;

    printf("Dados da primeira pessoa\n");
    printf("Nome: ");
    gets(nome1); // Pega char e strings
    printf("Idade: ");
    scanf("%d", &idade1);
    
    printf("Dados da segunda pessoa\n");
    printf("Nome: ");
    fseek(stdin, 0, SEEK_END); // LIMPA A QUEBRA DE LINHA anterior do 19
    gets(nome2);
    printf("Idade: ");
    scanf("%d", &idade2);
    
    media = (double)(idade1 + idade2) / 2; //Coloca 2.0 para entender que vc quer double ou (double) para transforma ou outro numero em inteiro

    printf("A idade media de %s e %s e de %.2lf anos", nome1, nome2, media);

    return 0;
}