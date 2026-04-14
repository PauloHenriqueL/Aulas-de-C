#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793


float calcular_media(float a, float b, float c) {
    return (a + b + c) / 3.0;
}

float calcular_media_ponderada(float a, float b, float c) {
    return ((a * 3) + (b * 4) + (c * 5)) / 12.0;
}

float calcular_perimetro_circulo(float raio) {
    return 2.0 * PI * raio;
}

float calcular_area_circulo(float raio) {
    return PI * pow(raio, 2);
}

float calcular_area_triangulo(float base, float altura) {
    return (base * altura) / 2.0;
}

float calcular_area_caixa(float a, float b, float c) {
    return 2.0 * (a * b + b * c + c * a);
}

float calcular_volume_caixa(float a, float b, float c) {
    return a * b * c;
}

float calcular_area_cilindro(float raio, float altura) {
    return (2 * PI * pow(raio, 2)) + (2 * PI * raio * altura);
}

float calcular_volume_cilindro(float raio, float altura) {
    return PI * pow(raio, 2) * altura;
}

float calcular_hipotenusa(float lado1, float lado2) {
    return sqrt(pow(lado1, 2) + pow(lado2, 2));
}

float calcular_raiz_positiva(float a, float b, float c) {
    float delta = pow(b, 2) - 4 * a * c;
    if (delta < 0) {
        printf("Não existe raízes reais porque delta é menor que 0\n");
        return -1; 
    }
    return (-b + sqrt(delta)) / (2 * a);
}

int main() {
    float a, b, c, raio, altura;

    printf("\nLista 2\nExercicio 1\n\n");

    printf("Digite o valor de a, b e c: \n");
    scanf("%f %f %f", &a, &b, &c);
    printf("A) Media: = %.2f\n", calcular_media(a, b, c));

    printf("B) Media ponderada: de a, b, c onde a tem peso 3, b 4 e c 5 = %.2f\n", calcular_media_ponderada(a, b, c));

    printf("Digite o valor do raio r: \n");
    scanf("%f", &raio);
    printf("C) Perimetro: = %.2f\n", calcular_perimetro_circulo(raio));

    printf("D) Area do circulo: = %.2f\n", calcular_area_circulo(raio));

    printf("Digite a base b do triangulo e a altura h: \n");
    scanf("%f %f", &b, &altura);
    printf("E) Area do triangulo = %.2f\n", calcular_area_triangulo(b, altura));

    printf("Digite as 3 dimensoes de uma caixa a, b e c: \n");
    scanf("%f %f %f", &a, &b, &c);
    printf("F) Area da caixa: = %.2f\n", calcular_area_caixa(a, b, c));

    printf("G) Volume da caixa: = %.2f\n", calcular_volume_caixa(a, b, c));

    printf("Digite o raio e a altura de um cilindro: \n");
    scanf("%f %f", &raio, &altura);
    printf("H) Area do cilindro = %.2f\n", calcular_area_cilindro(raio, altura));

    printf("I) Volume do cilindro = %.2f\n", calcular_volume_cilindro(raio, altura));

    printf("Digite os lados a e b de um triangulo retangulo: \n");
    scanf("%f %f", &a, &b);
    printf("J) Hipotenusa do triangulo retangulo = %.2f\n", calcular_hipotenusa(a, b));

    printf("Digite os valores de a, b e c da equacao a*x^2 + b*x + c: \n");
    scanf("%f %f %f", &a, &b, &c);
    float raiz = calcular_raiz_positiva(a, b, c);
    if (raiz != -1) {
        printf("K) Raiz positiva é = %.2f\n", raiz);
    }

    return 0;
}