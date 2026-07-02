
#include <stdio.h>
#include <stdlib.h>   // rand, srand, malloc
#include <time.h>     // time (semente do aleatorio)

#define ALTURA  4     // numero de linhas da caverna  (matriz!)
#define LARGURA 4     // numero de colunas da caverna

// ----------------------------------------------------------------------------
//  TIPOS DE CADA COMODO (sala) da caverna
//  enum = uma lista de "nomes" para numeros (VAZIO=0, MONSTRO=1, ...)
// ----------------------------------------------------------------------------
typedef enum {
    VAZIO,      // nada de mais
    MONSTRO,    // tem um inimigo
    TESOURO,    // tem um bau
    DESCANSO,   // local seguro pra descansar
    ROCHA,      // parede solida (nao da pra entrar)
    SAIDA       // objetivo: chegar aqui
} TipoComodo;

// ----------------------------------------------------------------------------
//  STRUCT da Amanda (a personagem)  -> todos os status vao de 0 a 100
// ----------------------------------------------------------------------------
typedef struct {
    int saude;     // vida; se chegar a 0 => fim de jogo
    int defesa;    // reduz o dano que ela recebe
    int ataque;    // dano base que ela causa
    int dano;      // bonus de dano (somado ao ataque)
    int fome;      // se chegar a 0 => -10 de saude por turno
    int sede;      // se chegar a 0 => -10 de saude por turno
    int tem_chave; // 0 = nao tem, 1 = tem (abre baus trancados)
} Personagem;

// ----------------------------------------------------------------------------
//  STRUCT de cada comodo (cada celula da matriz da caverna)
// ----------------------------------------------------------------------------
typedef struct {
    TipoComodo tipo;
    int visitado;          // ja entrei aqui? (pro mapa)

    // se for MONSTRO:
    int monstro_vida;
    int monstro_defesa;    // o quanto e dificil de acertar (rolagem precisa passar)
    int monstro_ataque;    // pontaria do monstro (somada ao d20 dele)
    int monstro_dano;      // dano que ele causa quando acerta
    int monstro_tem_chave; // esse monstro guarda a chave?

    // se for TESOURO:
    int bau_aberto;
    int bau_precisa_chave;
    int bau_tem_armadilha;
} Comodo;

// ----------------------------------------------------------------------------
//  STRUCT da caverna inteira: uma MATRIZ de comodos + a posicao da Amanda
// ----------------------------------------------------------------------------
typedef struct {
    Comodo grade[ALTURA][LARGURA];
    int linha;   // posicao atual da Amanda (y)
    int coluna;  // posicao atual da Amanda (x)
} Caverna;

// ----------------------------------------------------------------------------
//  VETOR DE STRUCTS: os itens que podem aparecer nos baus.
//  Cada item soma (ou subtrai) valores nos status da Amanda.
// ----------------------------------------------------------------------------
typedef struct {
    char nome[30];
    int d_saude, d_defesa, d_ataque, d_dano, d_fome, d_sede;
} Item;

Item ITENS[] = {
    {"Maca suculenta",      10,  0,  0,  0, 30, 10},
    {"Cantil de agua",       0,  0,  0,  0,  0, 40},
    {"Carne assada",        15,  0,  0,  0, 40, -5},
    {"Espada enferrujada",   0,  0,  4, 12,  0,  0},
    {"Escudo de madeira",    0, 20,  0,  0,  0,  0},
    {"Pocao de vida",       40,  0,  0,  0,  0,  0},
    {"Amuleto da coragem",   0,  5,  5,  5,  0,  0},
};
#define N_ITENS (int)(sizeof(ITENS) / sizeof(ITENS[0]))

// ============================================================================
//  FUNCOES AUXILIARES
// ============================================================================

// Mantem um valor sempre entre 0 e 100.
int limita(int v) {
    if (v < 0)   return 0;
    if (v > 100) return 100;
    return v;
}

// Resolve UM ataque estilo D&D:
//   - rola 1d20 (numero de 1 a 20)
//   - soma o 'ataque' (pontaria) e compara com a 'defesa' do alvo
//   - se (ataque + d20) >= defesa  => acertou e devolve o 'dano'
//   - se o d20 deu 20 (critico)    => dobra o dano
//   - se errou                     => devolve 0
// 'quem' e so o nome de quem ataca, pra imprimir a rolagem.
int rola_ataque(const char *quem, int ataque, int dano, int defesa_alvo) {
    int d20 = rand() % 20 + 1;          // dado de 1 a 20
    int total = ataque + d20;
    printf("   %s: d20=%d + ataque %d = %d  (defesa do alvo: %d) -> ",
           quem, d20, ataque, total, defesa_alvo);

    if (total < defesa_alvo) {          // nao alcancou a defesa
        printf("ERROU!\n");
        return 0;
    }
    int causado = dano;
    if (d20 == 20) {                    // acerto critico!
        causado *= 2;
        printf("CRITICO! ");
    }
    printf("ACERTOU, %d de dano!\n", causado);
    return causado;
}

// >>> RECURSIVIDADE + MATRIZ <<<
// Verifica se da pra chegar do comodo (l,c) ate o comodo (alvoL,alvoC)
// andando so por comodos que nao sejam ROCHA. Classico "flood fill".
// 'visitado' marca onde a recursao ja passou (pra nao entrar em loop).
int alcancavel(Caverna *cav, int visitado[ALTURA][LARGURA],
               int l, int c, int alvoL, int alvoC) {
    // CASOS BASE (param a recursao):
    if (l < 0 || l >= ALTURA || c < 0 || c >= LARGURA) return 0; // saiu do mapa
    if (cav->grade[l][c].tipo == ROCHA) return 0;                // parede
    if (visitado[l][c])                 return 0;                // ja passei aqui
    visitado[l][c] = 1;
    if (l == alvoL && c == alvoC)       return 1;                // achei!

    // PASSO RECURSIVO: tenta os 4 vizinhos (frente, tras, esquerda, direita)
    return alcancavel(cav, visitado, l - 1, c, alvoL, alvoC)
        || alcancavel(cav, visitado, l + 1, c, alvoL, alvoC)
        || alcancavel(cav, visitado, l, c - 1, alvoL, alvoC)
        || alcancavel(cav, visitado, l, c + 1, alvoL, alvoC);
}

// Aplica os efeitos de um item nos status da Amanda (recebida por PONTEIRO,
// pra alterar a struct ORIGINAL -> por isso usamos '->').
void aplica_item(Personagem *p, Item it) {
    p->saude  = limita(p->saude  + it.d_saude);
    p->defesa = limita(p->defesa + it.d_defesa);
    p->ataque = limita(p->ataque + it.d_ataque);
    p->dano   = limita(p->dano   + it.d_dano);
    p->fome   = limita(p->fome   + it.d_fome);
    p->sede   = limita(p->sede   + it.d_sede);
    printf("   >> Amanda pegou: %s!\n", it.nome);
}

// Passa um turno: fome e sede caem 5; se algum chegar a 0, tira 10 de saude.
void passa_turno(Personagem *p) {
    p->fome = limita(p->fome - 5);
    p->sede = limita(p->sede - 5);

    int dano_total = 0;
    if (p->fome == 0) { printf("   !! Amanda esta faminta (-10 saude)\n");   dano_total += 10; }
    if (p->sede == 0) { printf("   !! Amanda esta desidratada (-10 saude)\n"); dano_total += 10; }
    p->saude = limita(p->saude - dano_total);
}

// Mostra a barra de status da Amanda.
void mostra_status(Personagem p) {
    printf("\n+----------------------------------------------------+\n");
    printf("| AMANDA  saude:%-3d  defesa:%-3d  ataque:%-3d  dano:%-3d |\n",
           p.saude, p.defesa, p.ataque, p.dano);
    printf("|         fome:%-3d   sede:%-3d    chave:%s            |\n",
           p.fome, p.sede, p.tem_chave ? "SIM" : "nao");
    printf("+----------------------------------------------------+\n");
}

// Desenha o mapa da caverna (so revela comodos ja visitados).
void mostra_mapa(Caverna cav) {
    printf("\n   MAPA (@ = voce, ? = inexplorado)\n");
    for (int l = 0; l < ALTURA; l++) {
        printf("   ");
        for (int c = 0; c < LARGURA; c++) {
            char ch;
            if (l == cav.linha && c == cav.coluna) ch = '@';
            else if (!cav.grade[l][c].visitado)    ch = '?';
            else switch (cav.grade[l][c].tipo) {
                case ROCHA:    ch = '#'; break;
                case SAIDA:    ch = 'S'; break;
                case MONSTRO:  ch = 'M'; break;
                case TESOURO:  ch = 'B'; break;
                case DESCANSO: ch = 'z'; break;
                default:       ch = '.'; break;
            }
            printf(" %c", ch);
        }
        printf("\n");
    }
}

// ============================================================================
//  GERACAO ALEATORIA DA CAVERNA
// ============================================================================
void gera_caverna(Caverna *cav) {
    int visitado[ALTURA][LARGURA];
    int tentativas = 0;

    do {
        // 1) sorteia o tipo de cada comodo
        for (int l = 0; l < ALTURA; l++) {
            for (int c = 0; c < LARGURA; c++) {
                Comodo *s = &cav->grade[l][c];
                s->visitado = 0;
                s->bau_aberto = 0;
                s->monstro_tem_chave = 0;

                int r = rand() % 100;
                if      (r < 15) s->tipo = ROCHA;
                else if (r < 40) s->tipo = MONSTRO;
                else if (r < 58) s->tipo = TESOURO;
                else if (r < 70) s->tipo = DESCANSO;
                else             s->tipo = VAZIO;

                // monstros mais fortes quanto mais longe da entrada
                int dist = l + c;
                s->monstro_vida   = 15 + dist * 4;
                s->monstro_defesa = 8 + dist;   // mais longe = mais dificil de acertar
                s->monstro_ataque = 4 + dist;   // pontaria do monstro
                s->monstro_dano   = 4 + dist;   // dano por acerto

                // baus: as vezes precisam de chave, as vezes tem armadilha
                s->bau_precisa_chave = rand() % 2;
                s->bau_tem_armadilha = (rand() % 3 == 0);
            }
        }

        // 2) entrada e saida sao fixas
        cav->grade[0][0].tipo = VAZIO;                 // entrada
        cav->grade[ALTURA-1][LARGURA-1].tipo = SAIDA;  // objetivo

        // 3) zera o 'visitado' e testa (RECURSAO) se da pra chegar na saida
        for (int l = 0; l < ALTURA; l++)
            for (int c = 0; c < LARGURA; c++)
                visitado[l][c] = 0;

        tentativas++;
    } while (!alcancavel(cav, visitado, 0, 0, ALTURA-1, LARGURA-1)
             && tentativas < 200);

    // 4) garante a regra da chave: se existe bau trancado, um monstro
    //    (alcancavel) OBRIGATORIAMENTE guarda a chave.
    int existe_bau_trancado = 0, deu_chave = 0;
    for (int l = 0; l < ALTURA; l++)
        for (int c = 0; c < LARGURA; c++)
            if (cav->grade[l][c].tipo == TESOURO &&
                cav->grade[l][c].bau_precisa_chave)
                existe_bau_trancado = 1;

    if (existe_bau_trancado) {
        for (int l = 0; l < ALTURA && !deu_chave; l++)
            for (int c = 0; c < LARGURA && !deu_chave; c++)
                if (cav->grade[l][c].tipo == MONSTRO && visitado[l][c]) {
                    cav->grade[l][c].monstro_tem_chave = 1;
                    deu_chave = 1;
                }
        // se nao havia monstro alcancavel, destranca todos os baus
        if (!deu_chave)
            for (int l = 0; l < ALTURA; l++)
                for (int c = 0; c < LARGURA; c++)
                    cav->grade[l][c].bau_precisa_chave = 0;
    }

    // 5) Amanda comeca na entrada
    cav->linha = 0;
    cav->coluna = 0;
    cav->grade[0][0].visitado = 1;
}

// ============================================================================
//  ACOES DENTRO DE UM COMODO
// ============================================================================

// Combate. Recebe a Amanda e o comodo por PONTEIRO (vai alterar os dois).
// Retorna 1 se Amanda venceu, 0 se fugiu.
int combate(Personagem *p, Comodo *sala) {
    printf("\n   *** UM MONSTRO APARECE! (vida %d, defesa %d, ataque %d, dano %d) ***\n",
           sala->monstro_vida, sala->monstro_defesa,
           sala->monstro_ataque, sala->monstro_dano);

    while (sala->monstro_vida > 0 && p->saude > 0) {
        printf("\n   Monstro: %d de vida | Amanda: %d de saude\n",
               sala->monstro_vida, p->saude);
        printf("   [1] Atacar   [2] Fugir > ");

        int op;
        if (scanf(" %d", &op) != 1) return 0;

        if (op == 1) {
            // Amanda ataca: ataque + d20 vs defesa do monstro
            int golpe = rola_ataque("Amanda", p->ataque, p->dano,
                                    sala->monstro_defesa);
            sala->monstro_vida -= golpe;
            if (sala->monstro_vida <= 0) break;     // monstro morreu

            // o monstro contra-ataca (mesma regra, contra a defesa da Amanda)
            int contra = rola_ataque("Monstro", sala->monstro_ataque,
                                     sala->monstro_dano, p->defesa);
            p->saude = limita(p->saude - contra);
        }
        else if (op == 2) {
            if (rand() % 2 == 0) {
                printf("   Amanda conseguiu fugir!\n");
                return 0;
            }
            printf("   Fuga falhou! O monstro ataca:\n");
            int contra = rola_ataque("Monstro", sala->monstro_ataque,
                                     sala->monstro_dano, p->defesa);
            p->saude = limita(p->saude - contra);
        }
    }

    if (p->saude > 0) {
        printf("   >> Amanda derrotou o monstro!\n");
        if (sala->monstro_tem_chave) {
            p->tem_chave = 1;
            printf("   >> O monstro deixou cair uma CHAVE!\n");
        }
        sala->tipo = VAZIO;   // o comodo agora esta livre
        return 1;
    }
    return 0;
}

// Tenta abrir o bau do comodo atual.
void abrir_bau(Personagem *p, Comodo *sala) {
    if (sala->bau_aberto) {
        printf("   Esse bau ja foi aberto.\n");
        return;
    }
    if (sala->bau_precisa_chave && !p->tem_chave) {
        printf("   O bau esta TRANCADO. Amanda precisa de uma chave!\n");
        return;
    }

    printf("   Amanda abre o bau...\n");
    if (sala->bau_tem_armadilha) {
        printf("   !! ARMADILHA! Amanda toma 15 de dano.\n");
        p->saude = limita(p->saude - 15);
    }
    Item premio = ITENS[rand() % N_ITENS];   // sorteia um item do vetor
    aplica_item(p, premio);
    sala->bau_aberto = 1;
}

// Descansa: recupera saude e um pouco de defesa.
void descansar(Personagem *p) {
    printf("   Amanda descansa em seguranca...\n");
    p->saude  = limita(p->saude + 25);
    p->defesa = limita(p->defesa + 5);
    printf("   >> +25 saude, +5 defesa.\n");
}

// ============================================================================
//  PROGRAMA PRINCIPAL
// ============================================================================
int main(int argc, char *argv[]) {
    // Sem argumento: partida aleatoria. Com argumento (ex.: ./jogo 42):
    // usa semente fixa, gerando sempre a MESMA caverna (util pra testar).
    if (argc > 1) srand(atoi(argv[1]));
    else          srand(time(NULL));

    // saude, defesa, ataque(pontaria), dano, fome, sede, tem_chave
    Personagem amanda = {100, 12, 8, 8, 100, 100, 0};
    Caverna caverna;
    gera_caverna(&caverna);

    printf("============================================\n");
    printf("        A CAVERNA DE AMANDA\n");
    printf("  Encontre a saida (S) sem morrer no caminho!\n");
    printf("============================================\n");

    int jogando = 1;
    while (jogando) {
        // comodo atual (ponteiro pra facilitar)
        Comodo *sala = &caverna.grade[caverna.linha][caverna.coluna];
        sala->visitado = 1;

        // se entrou num comodo com monstro vivo, luta na hora
        if (sala->tipo == MONSTRO && sala->monstro_vida > 0) {
            int venceu = combate(&amanda, sala);
            if (!venceu && amanda.saude > 0) {
                // fugiu: volta pra entrada como "recuo seguro"
                printf("   Amanda recua para a entrada.\n");
                caverna.linha = 0;
                caverna.coluna = 0;
            }
        }

        if (amanda.saude <= 0) {
            printf("\n   X_X  Amanda nao resistiu... FIM DE JOGO.\n");
            break;
        }

        mostra_mapa(caverna);
        mostra_status(amanda);

        // chegou na saida?
        if (sala->tipo == SAIDA) {
            printf("\n   *** Amanda encontrou a SAIDA! VOCE VENCEU! ***\n");
            break;
        }

        // monta o menu de acoes
        printf("\n   Comodo atual: ");
        switch (sala->tipo) {
            case TESOURO:  printf("ha um BAU aqui.\n");        break;
            case DESCANSO: printf("um lugar pra DESCANSAR.\n"); break;
            default:       printf("vazio.\n");                 break;
        }
        printf("   [w]frente [s]tras [a]esq [d]dir");
        if (sala->tipo == TESOURO && !sala->bau_aberto) printf(" [b]abrir bau");
        if (sala->tipo == DESCANSO)                     printf(" [r]descansar");
        printf(" [q]sair\n   > ");

        char cmd;
        if (scanf(" %c", &cmd) != 1) break;   // fim da entrada

        // calcula o destino do movimento
        int nl = caverna.linha, nc = caverna.coluna;
        int moveu = 0;
        if      (cmd == 'w') { nl--; moveu = 1; }
        else if (cmd == 's') { nl++; moveu = 1; }
        else if (cmd == 'a') { nc--; moveu = 1; }
        else if (cmd == 'd') { nc++; moveu = 1; }
        else if (cmd == 'b' && sala->tipo == TESOURO) { abrir_bau(&amanda, sala); passa_turno(&amanda); }
        else if (cmd == 'r' && sala->tipo == DESCANSO){ descansar(&amanda);      passa_turno(&amanda); }
        else if (cmd == 'q') { printf("   Ate a proxima!\n"); break; }
        else printf("   Comando invalido.\n");

        if (moveu) {
            // checa limites e parede
            if (nl < 0 || nl >= ALTURA || nc < 0 || nc >= LARGURA) {
                printf("   Tem uma parede ai. Amanda nao se move.\n");
            } else if (caverna.grade[nl][nc].tipo == ROCHA) {
                printf("   Rocha solida bloqueia o caminho.\n");
            } else {
                caverna.linha = nl;
                caverna.coluna = nc;
                passa_turno(&amanda);   // andar gasta um turno
            }
        }

        if (amanda.saude <= 0) {
            printf("\n   X_X  Amanda nao resistiu... FIM DE JOGO.\n");
            break;
        }
    }

    return 0;
}
