#include <stdio.h>


int main() {
    int arranjo[1000];
    int i = 0;

    FILE *meu_arquivo = fopen("dados.txt", "r");

    if (meu_arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    while (fscanf(meu_arquivo, "%d", &arranjo[i]) == 1)
    {
        printf("%d\n", arranjo[i]);
        i++;
    }

    fclose(meu_arquivo);
    return 0;
}
