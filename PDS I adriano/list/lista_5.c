#include <stdio.h>
#include <math.h>

int fat(int n){
    int mult = 1;
    for (int i = n; i>0; i--){
        mult = mult * i;
    }
    return mult;
}

int mdc(int a, int b){

    while(b != 0){
        int resto = (a % b);
        a = b;
        b = resto;
    }
    return a;
}

int mdc3(int a, int b, int c){
    return mdc(mdc(a, b), c);
}

int fib(int a){
    int ant = 0, atual = 1, novo;
    if( a == 0) return 0;
        for(int i = 1; i<a; i++){
            novo = ant + atual;
            ant = atual;
            atual = novo;
        }
        return atual;
}

int primo(int a){
    if (a < 2) return 0;
    for (int i = 2; i < a; i++){
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}

void decrescente(int a){
    a = a -1;
    while(a > 0){
        printf("%d\n", (a));
        a--;
    }
}

int res(int a, int b){
    while (a >= b)
    {
        a = (a - b);
    }
    return a;
}

int form(int a){
    int soma = 0;
    for (int i = 1; i <= a; i++){
        soma = soma + i*i;
    }
    return soma;
}

int mmc(int a, int b){
    return (a * b) / mdc(a, b);
}

int div(int a, int b){
    int q = 0;
    while (a >= b){
        a = a - b;
        q++;
    }
    return q;
}

float raiz(float a){
    if (a == 0) return 0;
    float r = a / 2;   
    float novo;
    while (1) {
        novo = (r + a/r) / 2;
        if (fabs(novo - r) < 0.001) return novo;
        r = novo;
    }
}

int dig(int a){
    int soma = 0;
    while (a > 0)
    {
        soma = soma + (a % 10);
        a = (a/10);
    }
    return soma;
}

int expo(int a, int b){
    int mult = 1;
    for(int i = 1; i<= b; i++){
        mult = mult * a;
    }
    return mult;
}

void cresc(int a){
    for (int i = 1; i<=a; i++){
        printf("%d\n", i);
    }
}

int main(){
    int n, a, b, c;
    float x;

    printf("Digite um valor n para retornar o fatorial\n");
    scanf("%d", &n);
    printf("a) fat = %d\n", fat(n));

    printf("Digite dois numeros para retornar o maximo divisor comum\n");
    scanf("%d %d", &a, &b);
    printf("b) MDC(%d, %d) = %d\n", a, b, mdc(a, b));

    printf("\nDigite tres numeros para retornar o maximo divisor comum\n");
    scanf("%d %d %d", &a, &b, &c);
    printf("c) MDC(%d, %d, %d) = %d\n", a, b, c, mdc3(a, b, c));

    printf("Digite o numero n para retornar o n-esimo termo de Fibonacci\n");
    scanf("%d", &n);
    printf("d) fib(%d) = %d\n", n, fib(n));

    printf("e) Digite um numero para ver se ele eh primo\n");
    scanf("%d", &n);
    if (primo(n)){
        printf("e) eh primo\n");
    } else {
        printf("e) Nao eh primo\n");
    }

    printf("Digite um numero para escrever os decrescente\n");
    scanf("%d", &n);
    printf("f) Decrescente(%d)\n", n);
    decrescente(n);

    printf("Digite dois numeros para trazer o resto da divisao\n");
    scanf("%d %d", &a, &b);
    printf("g) res(%d, %d) = %d\n", a, b, res(a,b));

    printf("Digite um n numero para retornar o valor do somatorio de i*i com i variando de 1 a n\n");
    scanf("%d", &n);
    printf("h) form(%d) = %d\n", n, form(n));

    printf("Digite dois numeros para encontrar o menor multiplo comum\n");
    scanf("%d %d", &a, &b);
    printf("i) mmc(%d, %d) = %d\n", a, b, mmc(a, b));

    printf("Digite dois numeros para retorna a divisao intira dos dois\n");
    scanf("%d %d", &a, &b);
    printf("J) div(%d, %d) = %d\n", a, b, div(a,b));

    printf("Digite um numero para retorna a raiz quadrada com precisão de 0.001\n");
    scanf("%f", &x);
    printf("l) sqrt(%.3f) = %.3f\n", x, raiz(x));

    printf("Digite um numero para retornar a soma dos digitos desse numero\n");
    scanf("%d", &a);
    printf("m) dig(%d) = %d\n", a, dig(a));

    printf("Digite um numero k e outro n para retorna k elavado a n\n");
    scanf("%d %d", &a, &b);
    printf("N) exp(%d, %d) = %d\n", a, b, expo(a, b));

    printf("Digite um numero para escrevermos a ordem crescente desse numero\n");
    scanf("%d", &a);
    printf("o) crescente(%d)\n", a);
    cresc(a);

    return 0;
}