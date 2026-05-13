#include <stdio.h>
#include <math.h>


int main() {
    float arranjo[100];
    int i = 0;

    FILE *meu_arquivo = fopen("dados.txt", "r");

    if (meu_arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 0;
    }

    while (fscanf(meu_arquivo, "%f", &arranjo[i]) == 1) {
        printf("%.2f\n", arranjo[i]);
        i++;
    }
    
    fclose(meu_arquivo);
    printf("%d\n", i);
    return 0;
}