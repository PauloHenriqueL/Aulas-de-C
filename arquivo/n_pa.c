#include <stdio.h>

int main(){
    float n, r, a1;
    printf("digite o N° de termos da P.A");
    scanf("%f", &n);
    printf("digite o primeiro termo da P.A");
    scanf("%f", &a1);
    printf("digite a razao da P.A");
    scanf("%f", &r);
    a1 = a1 + (r * (n - 1));
    printf("O valor do ultimo termo %.2lf", a1);
    return 0;
}