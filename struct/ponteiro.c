#include <stdio.h>

typedef struct {
    int x;
} ponto;

typedef struct exemplo {
    int x;
} ex;

void printa_ponto_diretamente(ponto *p){
    printf("Ponto: (%d)\n", p->x);
};

void printa_ponto_referencia(ponto *p){
    printf("Ponto: (%d)\n", (*p).x);
};

void print_ponto_struct(struct exemplo p1){
    printf("Ponto x = %.d\n", p1.x);
}

void main(){

    ponto p = {10};
    ex x = {11};

    printa_ponto_diretamente(&p);
    printa_ponto_referencia(&p);
    print_ponto_struct(x);

}