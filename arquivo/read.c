#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo; // Declaramos um ponteiro do tipo FILE.

    arquivo = fopen("meu_arquivo.txt", "w"); // "w" cria um arquivo novo. Se ele já existir, ele apaga e começa denovo;
    
    if (arquivo == NULL) { // sempre verificar se o arquivo abriu corretamente
        printf("Erro ao criar o arquivo!\n");
        return 1; // Encerra o programa com erro
    }

    fprintf(arquivo, "Primeira linha: Aprendendo arquivos em C!\n"); // Escrevemos com fprintf
    
    fclose(arquivo); // SEMPRE feche o arquivo após terminar. Isso salva.

    
    arquivo = fopen("meu_arquivo.txt", "a"); // O "a" adiciona texto no final.
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para edição!\n");
        return 1;
    }

    fprintf(arquivo, "Segunda linha: Adicionando mais conteudo sem apagar o anterior.\n");
    fclose(arquivo);

    arquivo = fopen("meu_arquivo.txt", "r");  // O "r" le o arquivo.

    // Variável para guardar o texto lido (linha por linha)
    char linha[200];

    // O fgets lê uma linha inteira do arquivo por vez. 
    // Colocamos dentro de um while para ler até chegar ao fim do arquivo (EOF - End Of File).
    while (fgets(linha, 200, arquivo) != NULL) {
        printf("%s", linha);
    }
    fclose(arquivo);
    return 0;
}