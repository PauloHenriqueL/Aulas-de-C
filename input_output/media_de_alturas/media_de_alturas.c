#include <stdio.h>

#define MAX_PESSOAS 100

int main(){
    int idade[MAX_PESSOAS];
    float altura[MAX_PESSOAS];
    int n = 0;
    float altura_total = 0;
    float media = 0;
    int contador = 0;

    printf("Digite idade e altura das pessoas.\n");
    printf("Para encerrar, digite uma idade menor ou igual a zero.\n\n");

    while (n < MAX_PESSOAS)
    {
        printf("Digite a idade da pessoa %d: ", n + 1);
        scanf("%d", &idade[n]);
        
        if(idade[n] <= 0){
            break;
        }


        printf("Digite a altura da pessoa %d: ", n + 1);
        scanf("%f", &altura[n]);

        n++;
    }
    

    for(int i = 0; i < n; i++){
        if(idade[i] > 40 && idade[i] < 50){
            altura_total = altura_total + altura[i];
            contador++;
        }
    }

    if(contador > 0){
        media = altura_total / contador;
        printf("Media: %.2f", media);
    } else {
        printf("Nenhum pessoa na faixa etaria\n");
    }


    return 0;
}