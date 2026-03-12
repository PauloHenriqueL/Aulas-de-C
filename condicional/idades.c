#include <stdio.h>
#include <math.h>


int main() {
    int idade, qt = 0;
    float media, altura; 

    while(1) {
        printf("Qual sua idade?\n");
        scanf("%d", &idade);
        if(idade <= 0){
            break;
        }
        printf("Qual sua altura?\n");
        scanf("%f", &altura);

        if(idade >= 40 && idade <= 50) {
            media += altura;
            qt++;
        }
    }
    if(qt == 0) {
        printf("Nenhum valor foi adicinado");
    }
    else printf("a media de altura das pessoas, que possuem idade entre 40 e 50 e: %.2lf", media/qt);

    return 0;
}