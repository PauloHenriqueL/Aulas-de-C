#include <stdio.h>
#include <math.h>

int main() {
    int N, qt;

    printf("Qual a ordem da matriz? ");
    scanf("%d", &N);

    int mat[N][N];

    for (int i = 0; i < N; i++) { // pecore a linha
        for (int j = 0; j < N; j++) {// pecore a coluna
            printf("Elemento [%d,%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    printf("DIAGONAL PRINCIPAL:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", mat[i][i]);
    }

    qt = 0;
    for (int i = 0; i < N; i++) { // pecore a linha
        for (int j = 0; j < N; j++) {
            if (mat[i][j] < 0){
                qt++;
            }
        }
    }    
    printf("\nQUANTIDADE DE NEGATIVOS = %d\n", qt);

    return 0;
}