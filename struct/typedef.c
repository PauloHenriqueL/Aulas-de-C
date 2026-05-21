#include <stdio.h>

struct tipo_endereco{
    char rua[50];
    int numero;
};

typedef struct {
    char placa[10];
} carro;

typedef struct {
    int x;
}ponto;

float distancia(ponto p1, int p2){
    return (p1.x - p2);
}

void ler_coor(ponto *p1){
    int a;
    printf("Digite o valor do ponto");
    scanf("%d", &a);

    p1 -> x = a;
}

void main(){
    
    struct tipo_endereco casa = {"Rua das flores", 10};

    printf("Endereco da casa = %s %d\n", casa.rua, casa.numero);

    typedef struct tipo_endereco endereco;
    
    endereco trabalho = {"Lourdes", 10};
    printf("Endereco do trabalho = %s %d\n", trabalho.rua, trabalho.numero);


    carro civic1 = {"12432"};
    printf("Placa do civic: %s\n", civic1.placa);

    ponto x, y;
    printf("Escreva dois numero:");
    scanf("%d %d", &x.x, &y.x);
    printf("\n %.2f \n", distancia(x,y.x));


}