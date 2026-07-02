// ============================================================================
//  Treino C++  -  reconstruindo o sistema do jogo_amanda.c, mas em C++
//  Compile:  g++ -Wall treino.cpp -o treino
//  Rode:     ./treino
// ============================================================================

#include <bits/stdc++.h>

using namespace std;

// ============================================================================
//  LICAO 7 - O COMBATE DE VERDADE (um objeto ataca o outro)  *** FINAL ***
//
//  Agora a Amanda vai atacar o Goblin. O metodo recebe o ALVO por REFERENCIA
//  (o &), pra mexer no monstro DE VERDADE (e nao numa copia):
//
//      void atacar(personagem& alvo) {
//          int d = rolarAtaque(alvo.defesa);   // rola contra a defesa do alvo
//          alvo.tomarDano(d);                  // aplica o dano no alvo
//          cout << nome << " causou " << d << " em " << alvo.nome << endl;
//      }
//
//  Repare que ele REUSA dois metodos que voce ja fez: rolarAtaque e tomarDano.
//  E note: 'nome'/'rolarAtaque' sao do atacante; 'alvo.defesa'/'alvo.tomarDano'
//  sao do alvo. O '.' depois de 'alvo' acessa os campos/metodos DELE.
//
//  >>>>> CUIDADO COM O &  <<<<<
//  Se voce escrever  void atacar(personagem alvo)  (SEM o &), o C++ faz uma
//  COPIA do monstro. Voce bate na copia, o monstro real nunca perde vida...
//  e o loop de combate nunca termina! E a MESMA armadilha "por valor vs por
//  referencia" que voce viu no jogo em C (la voce usava ponteiro; aqui, &).
//
//  >>> SUA TAREFA <<<
//    1. Crie o metodo  void atacar(personagem& alvo)  na struct (modelo acima).
//    2. No main, faca o loop de combate:
//          while (amanda.estaViva() && goblin.estaViva()) {
//              amanda.atacar(goblin);
//              if (goblin.estaViva()) goblin.atacar(amanda);
//          }
//    3. No fim, imprima quem venceu (dica: quem ainda estaViva()).
// ============================================================================

struct personagem {
    int saude, defesa, ataque, dano, fome, sede;
    string nome;
    personagem(){
        nome = "Amanda";
        saude = 100;
        defesa = 12;
        ataque = 8;
        dano = 8;
        fome = 100;
        sede = 100;
    }

    personagem(string n, int s, int d, int a, int dn) {
        nome = n;
        saude = s;
        defesa = d;
        ataque = a;
        dano = dn;
        fome = 100;
        sede = 100;
    }

    int rolarAtaque(int defesaAlvo) {
        int d20 = (rand() % 20 + 1);
        if(d20 + ataque >= defesaAlvo) {
            if(d20 == 20) {
                return dano * 2;
            } else {
                return dano;
            }
        } else {
            return 0;
        }
    }
    void curar(int qtd){
        saude += qtd;
        if(saude > 100){
            saude = 100;
        }
    }
    void tomarDano(int qtd){
        saude -= qtd;
        if(saude < 0){
            saude = 0;
        }
    }
    void mostrarStatus(){
        cout << "Sua saude e: " << saude << " Sua defesa e: " << defesa 
            << " Seu ataque e: " << ataque << " Seu dano e: " << dano << " Sua fome e: "
            << fome << " Sua sede e: " << sede << " Seu nome é: " << nome << endl;
    }
    bool estaViva() {
        if(saude > 0){
            return true;
        } else {
            return false;
        }
    }
    void atacar(personagem& alvo) {
        int d = rolarAtaque(alvo.defesa);   
        alvo.tomarDano(d);         
        cout << nome << " causou " << d << " em " << alvo.nome << endl;
    }
};


int main() {
    srand(time(0));
    personagem amanda;
    personagem goblin {"Goblin", 30, 15, 5, 6};
    goblin.mostrarStatus();
    if(amanda.estaViva()){
        cout << "Voce ta viva\n";
    };
    while (amanda.estaViva() && goblin.estaViva()) {
        amanda.atacar(goblin);
        if (goblin.estaViva()) goblin.atacar(amanda);
    }
    if(amanda.estaViva()){
        printf("\nAmanda venceu\n");
    } else {
        printf("\nGoblin venceu\n");
    }

    return 0;
}
