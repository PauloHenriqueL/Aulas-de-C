#include <stdio.h>

struct ponto{
    float coord_x;
    float coord_y;
};

struct circulo{
    float raio;
    struct ponto centro; 
};

struct cilindro{
    float altura;
    struct circulo base;
};

void printPoint(struct ponto p1){
    printf("Ponto x = %.2f, y = %.2f\n", p1.coord_x, p1.coord_y);
}

struct tipo_endereco {
    char rua[50];
    int numero;
};



void main(){

    typedef struct tipo_endereco endereco;

    struct ponto p1 = {10, 20};
    printPoint(p1);

    struct circulo c1 = {4, 11, 22};
    printf("Circulo : R = %.2f, C = (%.2f, %.2f)\n",
    c1.raio,
    c1.centro.coord_x,
    c1.centro.coord_y);



}