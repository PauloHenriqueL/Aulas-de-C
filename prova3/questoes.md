# Prova 3 — Treino de Estruturas (`struct`) e Recursividade

> Lista de exercícios para treinar. Tente resolver **sem olhar o gabarito** (`gabarito.md`).
> Para as questões de "escreva a função", compile e teste no `treino.c`.
> Para as questões de "qual a saída", escreva sua resposta no papel **antes** de rodar.

---

## Parte 1 — Structs: conceitos e leitura de código

### Q1. Qual é a saída?
```c
#include <stdio.h>

struct ponto {
    int x;
    int y;
};

int main() {
    struct ponto p = {3, 7};
    p.x = p.x + p.y;
    printf("%d %d\n", p.x, p.y);
    return 0;
}
```

### Q2. Qual é a saída?
```c
#include <stdio.h>

typedef struct {
    char nome[20];
    int idade;
} Pessoa;

void aniversario(Pessoa pes) {   // recebe por VALOR
    pes.idade = pes.idade + 1;
}

int main() {
    Pessoa a = {"Ana", 20};
    aniversario(a);
    printf("%s tem %d anos\n", a.nome, a.idade);
    return 0;
}
```
*(Atenção: por valor ou por referência? O que muda?)*

### Q3. Qual é a saída? (struct aninhada)
```c
#include <stdio.h>

struct ponto { float x, y; };
struct circulo {
    float raio;
    struct ponto centro;
};

int main() {
    struct circulo c = {2.0, {5.0, 8.0}};
    printf("R=%.1f centro=(%.1f, %.1f)\n", c.raio, c.centro.x, c.centro.y);
    return 0;
}
```

### Q4. Qual é a saída? (ponteiro pra struct)
```c
#include <stdio.h>

typedef struct { int valor; } Caixa;

void dobra(Caixa *c) {   // recebe por REFERÊNCIA
    c->valor = c->valor * 2;
}

int main() {
    Caixa cx = {10};
    dobra(&cx);
    printf("%d\n", cx.valor);
    return 0;
}
```

### Q5. Encontre o(s) erro(s)
Esse código não compila. Aponte o que está errado e corrija:
```c
#include <stdio.h>

struct aluno {
    char nome[30];
    float nota;
}

int main() {
    struct aluno a;
    a->nome = "Joao";
    a.nota = 8.5;
    printf("%s %.1f\n", a.nome, a.nota);
    return 0;
}
```
*(Dica: são 3 erros.)*

---

## Parte 2 — Structs: escreva o código

### Q6. Defina o tipo
Usando `typedef`, defina um tipo `Retangulo` que guarde `largura` e `altura` (ambos `float`).
Depois escreva uma função `float area(Retangulo r)` que retorne a área.

### Q7. Função que retorna struct
Defina `typedef struct { int x, y; } Ponto;` e escreva uma função
`Ponto criar_ponto(int x, int y)` que crie e retorne um ponto com esses valores.

### Q8. Ponteiro e leitura
Escreva `void ler_aluno(Aluno *a)` que use `scanf` para preencher os campos
`nome` (string) e `nota` (float) de um aluno passado por referência.
Use o tipo:
```c
typedef struct {
    char nome[30];
    float nota;
} Aluno;
```

### Q9. Vetor de structs
Dado um vetor de `n` alunos, escreva uma função
`float media_da_turma(Aluno turma[], int n)` que retorne a média das notas.

### Q10. Vetor de structs — busca
Escreva `Aluno melhor_aluno(Aluno turma[], int n)` que retorne o aluno
com a **maior** nota da turma.

---

## Parte 3 — Recursividade: leitura e rastreio

### Q11. Qual é a saída?
```c
#include <stdio.h>

int f(int n) {
    if (n == 0) return 0;
    return n + f(n - 1);
}

int main() {
    printf("%d\n", f(4));
    return 0;
}
```

### Q12. Qual é a saída? (ordem importa!)
```c
#include <stdio.h>

void g(int n) {
    if (n > 0) {
        g(n - 1);
        printf("%d ", n);
    }
}

int main() {
    g(3);
    printf("\n");
    return 0;
}
```
*(Agora compare: e se as duas linhas dentro do `if` trocassem de ordem?)*

### Q13. Quantas vezes `h` é chamada?
```c
int h(int n) {
    if (n <= 1) return 1;
    return h(n - 1) + h(n - 2);
}
```
Para `h(5)`, **conte** quantas chamadas de `h` acontecem no total (incluindo a primeira).

### Q14. Qual é a saída?
```c
#include <stdio.h>

int misterio(int a, int b) {
    if (b == 0) return a;
    return misterio(b, a % b);
}

int main() {
    printf("%d\n", misterio(48, 36));
    return 0;
}
```
*(O que essa função calcula?)*

---

## Parte 4 — Recursividade: escreva o código

> Regra do treino: **proibido usar `for` e `while`**. Tudo recursivo.

### Q15. Soma de 1 a n
Escreva `int soma(int n)` que retorne `1 + 2 + ... + n` recursivamente.

### Q16. Potência
Escreva `int potencia(int base, int exp)` que calcule `base^exp` (exp >= 0) sem laços.

### Q17. Soma dos dígitos
Escreva `int soma_digitos(int n)` que retorne a soma dos dígitos de um inteiro positivo.
Ex.: `soma_digitos(253)` → `2 + 5 + 3 = 10`.

### Q18. Conta dígitos
Escreva `int qtd_digitos(int n)` que retorne quantos dígitos tem `n` (n > 0).
Ex.: `qtd_digitos(4071)` → `4`.

### Q19. Inverte e imprime
Escreva `void imprime_invertido(int n)` que imprima os dígitos de `n` na ordem inversa.
Ex.: `imprime_invertido(123)` imprime `3 2 1`.

### Q20. Recursão sobre vetor
Escreva `int soma_vetor(int v[], int n)` que retorne a soma dos `n` primeiros
elementos do vetor, **recursivamente** (pense no caso `n == 0`).

### Q21. Busca recursiva
Escreva `int contem(int v[], int n, int alvo)` que retorne `1` se `alvo` está
entre os `n` primeiros elementos do vetor, e `0` caso contrário — recursivamente.

---

## Parte 5 — Combinando struct + recursão (nível prova)

### Q22. Fatorial dentro de struct
Dado:
```c
typedef struct {
    int n;
    int resultado;
} Calculo;
```
Escreva `Calculo calcular_fatorial(int n)` que retorne um `Calculo` preenchido
com `n` e com `resultado = n!` (use uma função recursiva de fatorial).

### Q23. Maior nota recursivamente
Usando o tipo `Aluno` da Q8, escreva
`float maior_nota(Aluno turma[], int n)` que retorne a maior nota da turma,
**recursivamente** (sem `for`/`while`).

### Q24. Soma de saldos
Dado:
```c
typedef struct {
    char titular[30];
    float saldo;
} Conta;
```
Escreva `float soma_saldos(Conta contas[], int n)` que retorne, recursivamente,
a soma de todos os saldos.

---

## Desafios (se sobrar tempo)

### D1. Palíndromo numérico
Escreva uma função recursiva que verifique se um número é palíndromo
(lê igual de trás pra frente). Ex.: `12321` é, `12345` não é.
*(Dica: pode usar `qtd_digitos` da Q18.)*

### D2. Torre de Hanói
Escreva `void hanoi(int n, char origem, char destino, char auxiliar)` que
imprima a sequência de movimentos para resolver a Torre de Hanói com `n` discos.
Saída esperada de cada movimento: `Mova disco de A para C`.

### D3. Ponto mais distante da origem
Dado um vetor de `Ponto` (`typedef struct { float x, y; } Ponto;`), escreva
uma função recursiva que retorne o ponto mais distante da origem `(0,0)`.
*(Distância² = x*x + y*y — não precisa de `sqrt`.)*

---

### Checklist antes da prova
- [ ] Sei a diferença entre `.` (struct/variável) e `->` (ponteiro pra struct).
- [ ] Sei quando uma função altera a struct original (por referência `*`) e quando não (por valor).
- [ ] Sei declarar struct com e sem `typedef`.
- [ ] Sei acessar campos de struct aninhada (`c.centro.x`).
- [ ] Toda recursão minha tem **caso base** (senão = loop infinito / stack overflow).
- [ ] Consigo rastrear no papel a ordem das chamadas recursivas.
