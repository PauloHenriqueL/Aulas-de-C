#include <stdio.h>
#include <math.h>


// Escreva um programa em C++ que lê de um arquivo o número de linhas, o número de
// colunas e todos os coeficientes de uma matriz.
int ler_arquivo(){
    float mat[100][100];
    int i;

    FILE *meu_arquivo = fopen("dados.txt", "r");

    while (fscanf(meu_arquivo, "%f", &mat[i][i]))
    {
        i++;
    }


    return i;
}

// 2. Escreva uma função que recebe uma matriz quadrada de dimensão ne que retorna a
// média dos elementos armazenados na matriz. O cabeçalho da função deve ser o seguinte:
// float media_matriz(int n, float mat[][100])


// 3. Escreva uma função que recebe uma matriz quadrada Ade dimensão ne que transforma
// A em uma matriz identidade. O cabeçalho da função deve ser o seguinte:
// void identidade(int n, float A[][100])



// 4. Escreva uma função que recebe uma matriz quadrada Ade dimensão ne que retorna
// uma matriz Tque é a transposta de A. O cabeçalho da função deve ser o seguinte:
// void transposta(int n, float A[][100], float T[][100])



// 5. Escreva uma função que testa se uma matriz quadrada Ade dimensão né simétrica. O
// cabeçalho da função deve ser o seguinte:
// bool simetrica(int n, float A[][100])



// 6. Escreva uma função que recebe duas matrizes quadradas Ae Bde dimensão ne que
// retorna uma matriz Sque é a soma de Ae B. O cabeçalho da função deve ser o seguinte:
// void soma_matriz(int n, float A[][100], float B[][100], float S[][100])



// 7. Escreva uma função que recebe duas matrizes quadradas Ae Bde dimensão ne que
// retorna uma matriz Pque é o produto de Ae B. O cabeçalho da função deve ser o seguinte:
// void mult_matriz(int n, float A[][100], float B[][100], float P[][100])