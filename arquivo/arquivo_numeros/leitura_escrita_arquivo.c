#include <stdio.h>

#define MAX_FILENAME 100
#define NUM_ELEMENTS 5

int main(){
    int numeros[NUM_ELEMENTS];
    char nome_arquivo[MAX_FILENAME];

    printf("=== Leitura de Números ===\n");
    for (int i = 0; i < NUM_ELEMENTS; i++){
        printf("Digite o %d número: ", i + 1);
        if (scanf("%d", &numeros[i]) != 1) {
            printf("Erro: entrada inválida\n");
            return 1;
        }
    }

    printf("\nDigite o nome do arquivo: ");
    if (scanf("%99s", nome_arquivo) != 1) {
        printf("Erro: nome do arquivo inválido\n");
        return 1;
    }

    FILE* arquivo = fopen(nome_arquivo, "w+t");
    if (arquivo == NULL) {
        printf("Erro: não foi possível criar o arquivo '%s'\n", nome_arquivo);
        return 1;
    }

    printf("\n=== Escrevendo no arquivo ===\n");
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        if (fprintf(arquivo, "%d\n", numeros[i]) < 0) {
            printf("Erro ao escrever no arquivo\n");
            fclose(arquivo);
            return 1;
        }
    }

    rewind(arquivo);

    printf("\n=== Lendo do arquivo ===\n");
    int lidos[NUM_ELEMENTS];
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        if (fscanf(arquivo, "%d", &lidos[i]) != 1) {
            printf("Erro ao ler do arquivo\n");
            fclose(arquivo);
            return 1;
        }
        printf("Número %d: %d\n", i + 1, lidos[i]);
    }

    if (fclose(arquivo) != 0) {
        printf("Erro ao fechar o arquivo\n");
        return 1;
    }

    printf("\n✓ Programa executado com sucesso!\n");
    return 0;
}
