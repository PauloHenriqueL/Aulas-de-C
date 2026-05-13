#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// 2. Escreva uma função que recebe uma matriz quadrada de dimensão n e que retorna a
// média dos elementos armazenados na matriz. O cabeçalho da função deve ser o seguinte:
// float media_matriz(int n, float mat[][100])
float media_matriz(int n, float matriz[][100]){
    float media, soma = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            soma = soma + matriz[i][j];
        }
    }

    media = soma / (n * n);
    return media;
}

// 3. Escreva uma função que recebe uma matriz quadrada A de dimensão n e que transforma
// A em uma matriz identidade. O cabeçalho da função deve ser o seguinte:
// void identidade(int n, float A[][100])
void identidade(int n, float A[][100]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

        if(j == i){
            A[i][j] = 1.0;
        }
        else{
            A[i][j] = 0.0;
        }
        }
    }
}


// 4. Escreva uma função que recebe uma matriz quadrada Ade dimensão ne que retorna
// uma matriz Tque é a transposta de A. O cabeçalho da função deve ser o seguinte:
// void transposta(int n, float A[][100], float T[][100])
void transposta(int n, float A[][100], float T[][100]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            T[j][i] = A[i][j];
        }
    }
}


// 5. Escreva uma função que testa se uma matriz quadrada Ade dimensão né simétrica. O
// cabeçalho da função deve ser o seguinte:
// bool simetrica(int n, float A[][100])
bool simetrica(int n, float A[][100]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(A[i][j] != A[j][i]){
                return false;
            }
        }
    }
    return true;
}


// 6. Escreva uma função que recebe duas matrizes quadradas Ae Bde dimensão ne que
// retorna uma matriz Sque é a soma de Ae B. O cabeçalho da função deve ser o seguinte:
// void soma_matriz(int n, float A[][100], float B[][100], float S[][100])
void soma_matriz(int n, float A[][100], float B[][100], float S[][100]) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            S[i][j] = A[i][j] + B[i][j];
        }
    }
}


// 7. Escreva uma função que recebe duas matrizes quadradas Ae Bde dimensão ne que
// retorna uma matriz Pque é o produto de Ae B. O cabeçalho da função deve ser o seguinte:
// void mult_matriz(int n, float A[][100], float B[][100], float P[][100])

void mult_matriz(int n, float A[][100], float B[][100], float P[][100]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            P[i][j] = 0;
            for(int k = 0; k < n; k++){
                P[i][j] = P[i][j] + (A[i][k] * B[k][j]);
            }
        }
    }
}