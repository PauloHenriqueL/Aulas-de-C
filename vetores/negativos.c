#include <stdio.h>

int main() {
    int N;

    printf("Quantos numeros voce vai digitar? ");
    scanf("%d", &N);

    int vet[N]; // declaração de vertor

    for (int i = 0; i < N; i++) {// Vetor começa no 0 e vai até n-1
        printf("Digite um numero: ");
        scanf("%d", &vet[i]);
    }

    printf("\nNUMEROS NEGATIVOS:\n");
    for (int i = 0; i<N; i++) {
        if (vet[i] < 0) {
            printf("%d\n", vet[i]);
        }
    }
    return 0;
}