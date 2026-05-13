#include <stdio.h>
#include <math.h>

int main(){
    float mat[100][100];
    int i, j, linha, coluna;


    FILE *arq_escrita = fopen("dados.txt", "w");
    
    if (arq_escrita == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }
    fprintf(arq_escrita, "3 4\n");
    fprintf(arq_escrita, "1 2 3 4\n");
    fprintf(arq_escrita, "5 6 7 8\n");
    fprintf(arq_escrita, "9 10 11 12\n");
    fclose(arq_escrita);

    printf("Arquivo 'dados.txt' criado com sucesso!\n");


    FILE *meu_arquivo = fopen("dados.txt", "r");
    if (meu_arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 0;
    }

    fscanf(meu_arquivo, "%d", &linha);
    fscanf(meu_arquivo, "%d", &coluna);
    for (i = 0; i < linha; i++){
        for (j = 0; j < coluna; j++){
            fscanf(meu_arquivo, "%f", &mat[i][j]);
            printf("%.2f\n", mat[i][j]);
        }
    }
    fclose(meu_arquivo);

    return 0;
}
