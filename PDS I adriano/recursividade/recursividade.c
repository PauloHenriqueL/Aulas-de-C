#include <stdio.h>


int fat(int n){
    if (n <= 1) {
        return 1;
    } else {
        return n * fat(n - 1);
    }
}

int mdc(int a, int b){
    if(b == 0){
        return a;
    } else {
        return mdc(b, a%b);
    }
}

int fib(int n){
    if(n == 1){
        return 0;
    } else if( n == 2){
        return 1;
    } else {
        return fib(n-1) + fib(n-2);
    }
}

int mmc(int a, int b){
    return (a*b) / mdc(a, b);
}

int primo(int x, int divisor){
    if(x < 2){
        return 0;
    } else if(divisor == 1){
        return 1;
    } else if (x % divisor == 0){
        return 0;
    } else
        return primo(x, divisor -1);
}

void desc(int a){

    if(a>0){
        printf("%d, ", a);
        desc(a-1);
    }
}

int resto(int a, int b){
    if(a < b){
        return a;
    } else {
        return resto(a - b, b);
    }
}

int form(int a){
    if(a == 1){
        return 1;
    } else {
        return (a*a) + form(a-1);
    }
}

int div(int a, int b){
    if(a < b){
        return 0;
    } else {
        return 1 + div(a - b, b);
    }
}

double raizaux(double a, double chute, double passo){
    if(passo < 0.001){
        return chute;
    } else if(chute * chute <= a) {
        return raizaux(a, chute+passo, passo);
    } else if(chute * chute > a) {
        return raizaux(a, chute - passo, passo/10);
    }
}

double raiz(double a){
    return raizaux(a, 0, 1);
}

int dig(int a){
    if(a == 0){
        return 0;
    } else {
    return (a % 10) + dig(a / 10);
    }
}

int pot(int a, int b){
    if(b == 0){
        return 1;
    } else {
        return a * pot(a, b-1);
    }
}

void cres(int a){

    if(a>0){
        cres(a-1);
        printf("%d, ", a);
    }
}


int main(){ 
    int n, r, a, b, m, c;
    double w;

    printf("a) Digite o fatorial que quer descobrir: ");
    scanf(" %d", &n);
    r = fat(n);
    printf("%d\n", r);

    printf("b) Digite o valor de A e B para encontrar o MDC: \n");
    scanf("%d %d", &a, &b);
    m = mdc(a, b);
    printf("O mdc(a, b) = %d\n", m);

    printf("c) Digite o valor de A, B, C para encontrar o MDC: \n");
    scanf("%d %d %d", &a, &b, &c);
    m = mdc(a, b);
    m = mdc(m, c);
    printf("O mdc(a, b, c) = %d\n", m);


    printf("d) Digita n-esimo termo da serie de Fibonacc que vc quer descobrir: \n");
    scanf("%d", &n);
    n = fib(n);
    printf("O n-esimo termo de Fibonacc: %d\n", n);


    printf("e) Digite um numero x para testar se é primo: ");
    scanf("%d", &a);
    if(primo(a, a-1) == 1){
        printf("E primo\n");
    } else {
        printf("Nao e primo\n");
    }

    printf("f) Digite um numero x para descobrir a seguência descrescente: ");
    scanf("%d", &a);
    desc(a-1);

    printf("g) Digite A e B para saber o resto da divisão: ");
    scanf("%d %d", &a, &b);
    printf("%d\n", resto(a, b));

    printf("h) Digite A para retorna o valor do somatório de i*i, com i variando de 1 até n: ");
    scanf("%d", &a);
    printf("%d\n", form(a));

    printf("i) mmc(a, b): retorna o menor múltiplo comum de a e b: ");
    scanf("%d %d", &a, &b);
    printf("%d\n", mmc(a, b));

    printf("j) div(a, b): retorna o resultado da divisão inteira de a por b. ");
    scanf("%d %d", &a, &b);
    printf("%d\n", div(a, b));

    printf("l) sqrt(n): retorna a raiz quadrada de n (com precisão de 0.001). ");
    scanf("%lf", &w);
    printf("%f\n", raiz(w));


    printf("m) dig(n): retorna a soma dos dígitos de um inteiro positivo n. ");
    scanf("%d", &a);
    printf("%d\n", dig(a));


    printf("n) exp(k, n): retorna k n");
    scanf("%d %d", &a, &b);
    printf("%d\n", pot(a, b));


    printf("o) crescente(x): escreve em ordem crescente, todos os inteiros maiores que 0 e menores ou iguais a x. ");
    scanf("%d", &a);
    cres(a);

}
