#include <stdio.h>
#include <math.h>


float maior(float a, float b, float c){
    if (a >= b && a >= c) {
        return a;
    } else if (b >= c) {
        return b;
    } else {
        return c;
    }
}

float menor(float a, float b, float c){
    if (a <= b && a <= c){
        return a;
    } else if (b <= c){
        return b;
    } else {
        return c;
    }
}

int par(int a) {
    if ((a % 2) == 0){
        return 1;
    } else {
        return 0;
    }
}

int entre(float a, float b, float c){
    if(b > c){
        float temp;
        temp = b;
        b = c;
        c = temp;
    }
    if (a >= b && a <= c)
    {
        return 1;
    } else {
        return 0;
    }
}

int fora(float a, float b, float c){
    if (b > c){
        float temp;
        temp = b;
        b = c;
        c = temp;
    }
    if (a < b || a > c){
        return 1;
    } else {
        return 0;
    }
}

int divisivel(int a, int b){
    if(a % b == 0){
        return 1;
    } else {
        return 0;
    }
}
int bissexto(int a){
    if (divisivel(a, 400) || (divisivel(a, 4) && !divisivel(a, 100))){
        return 1;
    } else {
        return 0;
    }
}

int main(){

    float a, b, c;
    int num, ano;

    printf("\n Lista 3\n Exercicio 1\n\n");
    printf("Digite o valor de a, b, c para verificar qual o menor e o maior\n");
    scanf("%f %f %f", &a, &b, &c);
    printf("a) maior entre os numeros %.2f\n", maior(a, b, c));
    printf("b) menor entre os numeros %.2f\n", menor(a, b, c));

    printf("exercicio 2 \n\n");
    printf("a) Digite um numero para testar se ele é par\n");
    scanf("%d", &num);
    if (par(num)) {
        printf("a) O numero é par\n");
    } else {
        printf("a) O numero é impar\n");
    }
    printf("\n");

    printf("b) Digite um numero x, depois digite um numero y e z para verificarmos se x está ENTRE y e z\n");
    scanf("%f %f %f", &a, &b, &c);
    if (entre(a, b, c)) {
        printf("b) X esta entre y e z\n");
    } else {
        printf("b) X não está entre Y e Z\n");
    }
    printf("\n");

    printf("c) Digite um numero x, depois digite um numero y e z para verificarmos se x está FORA y e z\n");
    scanf("%f %f %f", &a, &b, &c);
    if (fora(a, b, c)) {
        printf("c) X esta fora de Y e Z\n");
    } else {
        printf("c) X está dentro de Y e Z\n");
    }
    printf("\n");

    printf("exercicio 3 \n\n");
    printf("Digite um ano para verificar se ele eh um ano bissexto\n");
    scanf("%d", &ano);
    if (bissexto(ano)) {
        printf("Eh ano bissexto\n");
    } else {
        printf("Nao eh ano bissexto\n");
    }

    return 0;
}