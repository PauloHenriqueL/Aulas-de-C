#include <stdio.h>
#include <math.h>



int criar_arranjo(float arranjo[]) {
    int i = 0;

    FILE *meu_arquivo = fopen("dados.txt", "r");

    if (meu_arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 0;
    }

    while (fscanf(meu_arquivo, "%f", &arranjo[i]) == 1) {
        i++;
    }
    
    fclose(meu_arquivo);
    
    return i;
}


float calcular_media(float arranjo[], int n){
    float soma = 0, media = 0;
    
    for (int i = 0; i < n; i++){
        soma = arranjo[i] + soma;
    }

    media = soma/n;

    return media;
}


// 3. Escreva uma função em C++ que recebe um arranjo de números reais v e número de
// elementos n armazenados em v e que retorna a variância dos n elementos armazenados em v.
// Assuma que n é menor que o número máximo de elementos do arranjo (e.g. 1000).
float calcular_variancia(float arranjo[], int n){
    float soma = 0, media = 0, var = 0;
    media = calcular_media(arranjo, n);
    for(int i = 0; i < n; i++){
        var = var + (pow((arranjo[i]-media), 2));
    }
    return var / n;
}

// 4. Escreva uma função em C++ que recebe um arranjo de números reais v e número de
// elementos n armazenados em v e que retorna o maior dos n elementos armazenados em v.
// Assuma que n é menor que o número máximo de elementos do arranjo (e.g. 1000).
float retorna_maior(float arranjo[], int n){
    float maior = arranjo[0];
    
    for (int i = 1; i < n; i++){
        if (maior < arranjo[i]){
            maior = arranjo[i];
        }
    }

    return maior;
}

// 5. Escreva uma função em C++ que recebe um arranjo de números reais v e número de
// elementos n armazenados em v e que retorna o menor dos n elementos armazenados em v.
// Assuma que n é menor que o número máximo de elementos do arranjo (e.g. 1000).
float retorna_menor(float arranjo[], int n){
    float menor = arranjo[0];
    
    for (int i = 1; i < n; i++){
        if (menor > arranjo[i]){
            menor = arranjo[i];
        }
    }

    return menor;
}

// 6. Escreva uma função em C++ que recebe dois arranjoes de números reais u e v e a dimensão n
// dos dois arranjoes e que retorna o produto escalar de u e v. O produto escalar de dois arranjoes é
// dado pela seguinte expressão: u.v = u0.y0 + u1.y1 + u2.y2 + ... + un-1.yn-1. Assuma que n é menor
// que o número máximo de elementos do arranjo (e.g. 1000).
float produto_escalar(float arranjo1[], float arranjo2[], int n){
    float produto = 0;

    for(int i = 0; i < n; i++){
        produto = produto + (arranjo1[i] * arranjo2[i]);
    }

    return produto;
}


int main(){
    float arranjo1[1000], arranjo2[1000];
    int n;

    n = criar_arranjo(arranjo1);

    if (n == 0) {
        printf("Nenhum dado para processar.\n");
        return 1; 
    }
    for(int i = 0; i < n; i++) {
        arranjo2[i] = arranjo1[i] * 2.0;
    }

    float media = calcular_media(arranjo1, n);
    float variancia = calcular_variancia(arranjo1, n);
    float maior = retorna_maior(arranjo1, n);
    float menor = retorna_menor(arranjo1, n);
    float produto = produto_escalar(arranjo1, arranjo2, n); 

    printf("Resultados da Analise (%d elementos lidos):\n", n);
    printf("\n");
    printf("Media:           %.2f\n", media);
    printf("Variancia:       %.2f\n", variancia);
    printf("Maior valor:     %.2f\n", maior);
    printf("Menor valor:     %.2f\n", menor);
    printf("Produto Escalar: %.2f\n", produto);

    return 0;
}