#include <stdio.h>
#include <math.h>


int main(){
    double base, altura, area, perimetro, diagonal;

    printf("Base: ");
    scanf("%lf", &base);

    printf("Altura: ");
    scanf("%lf", &altura);

    area = (base * altura);
    perimetro = (2 * base) + (2 * altura);
    diagonal = sqrt(pow(base, 2.0) + pow(altura, 2.0)); // sqrt é a raiz, pow é a potenciação

    printf("Base: %.4lf, PERIMETRO: %.4lf, DIAGONAL: %.4lf", area, perimetro, diagonal);

    return 0;
}