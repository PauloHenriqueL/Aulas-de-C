
#include <stdio.h>
#include <stdlib.h>   // malloc, free  (precisa DESSE include p/ alocacao!)

typedef struct {
    char nome[20];
    int vida;
} personagem;


//  >>> SUA TAREFA <<<
//    PARTE A: aloque UMA Personagem com malloc, preencha com -> (ex.: vida=100),
//             imprima, e de free.
//    PARTE B: leia n, aloque um VETOR de n Personagem, preencha cada um num for
//             (usando [i].), imprima todos, e de free.
//
//  Dica do sizeof: use sizeof(Personagem) (o tipo), nao sizeof(int).
// ============================================================================

// ============================================================================
//  LICAO 3 - ESCREVER em arquivo (FILE, fopen, fprintf, fclose)
//
//  Um arquivo em C e manipulado por um PONTEIRO especial: FILE *.
//  O fluxo e sempre: ABRIR -> USAR -> FECHAR.
//
//  Como funciona (a IDEIA, nao e a tarefa):
//      FILE *arq = fopen("dados.txt", "w");   // "w" = write (cria/sobrescreve)
//      if (arq == NULL) { return 1; }         // SEMPRE checar (igual malloc!)
//      fprintf(arq, "Vida: %d\n", 100);       // igual printf, mas pro arquivo
//      fclose(arq);                           // SEMPRE fechar (isso SALVA!)
//
//  Os modos do fopen:
//      "w" -> escreve do zero (se o arquivo existe, APAGA tudo antes)
//      "a" -> escreve no FINAL (append, mantem o que ja tinha)
//      "r" -> le (Licao 4)
//
//  Tres pontos que caem em prova:
//    1. FILE * e um ponteiro -> cheque NULL depois do fopen.
//    2. fprintf(arq, ...) e igual printf, so que o 1o argumento e o arquivo.
//    3. Se esquecer o fclose, o conteudo pode nem ser salvo!
//
//  >>> SUA TAREFA <<<
//    1. Abra um arquivo "numeros.txt" no modo "w" (e cheque NULL).
//    2. Num for, escreva os numeros de 1 a 10, UM POR LINHA, usando fprintf.
//    3. Feche com fclose.
//    4. No final, de um printf na tela tipo "Arquivo gravado!" so pra saber
//       que terminou. (Depois a gente abre o numeros.txt pra conferir.)
// ============================================================================

int main() {

    int n; scanf("%d", &n); printf("\n");

    personagem *p = malloc(sizeof(personagem));
    p->vida = 100;
    free(p);

    personagem *grupo_de_personagens = malloc(n * sizeof(personagem));
    grupo_de_personagens[0].vida = 100;
    free(grupo_de_personagens);

    return 0;
}
