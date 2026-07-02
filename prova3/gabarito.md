# Gabarito — Prova 3 (Structs e Recursividade)

> ⚠️ Só abra depois de tentar! As funções de "escreva o código" têm **mais de uma**
> solução válida — o que importa é a lógica (caso base + passo recursivo).

---

## Parte 1 — Leitura de código

**Q1.** `10 7`
`p.x = 3 + 7 = 10`; `p.y` não muda.

**Q2.** `Ana tem 20 anos`
A struct foi passada **por valor**: a função recebe uma *cópia*, então o `+1`
some quando ela retorna. Para alterar de verdade seria preciso passar por
referência: `void aniversario(Pessoa *pes)` e usar `pes->idade++`, chamando `aniversario(&a)`.

**Q3.** `R=2.0 centro=(5.0, 8.0)`
Acesso encadeado: `c.centro.x` entra na struct `ponto` que está dentro de `circulo`.

**Q4.** `20`
Passada **por referência** (`Caixa *c`), a função altera a variável original via `c->valor`.

**Q5.** Três erros:
1. Falta `;` depois de fechar a struct: `};`
2. `a` não é ponteiro, então o acesso é com ponto: `a.nome` (não `a->nome`).
3. Não se atribui string a um vetor de char com `=`. Use `strcpy`:
   `strcpy(a.nome, "Joao");` (inclua `#include <string.h>`).

```c
#include <stdio.h>
#include <string.h>

struct aluno {
    char nome[30];
    float nota;
};   // <-- erro 1 corrigido

int main() {
    struct aluno a;
    strcpy(a.nome, "Joao");  // <-- erros 2 e 3 corrigidos
    a.nota = 8.5;
    printf("%s %.1f\n", a.nome, a.nota);
    return 0;
}
```

---

## Parte 2 — Structs

**Q6.**
```c
typedef struct {
    float largura;
    float altura;
} Retangulo;

float area(Retangulo r) {
    return r.largura * r.altura;
}
```

**Q7.**
```c
typedef struct { int x, y; } Ponto;

Ponto criar_ponto(int x, int y) {
    Ponto p;
    p.x = x;
    p.y = y;
    return p;
}
```

**Q8.**
```c
void ler_aluno(Aluno *a) {
    printf("Nome: ");
    scanf("%s", a->nome);     // string: SEM & (nome ja e um endereco)
    printf("Nota: ");
    scanf("%f", &a->nota);    // float: COM &
}
```

**Q9.**
```c
float media_da_turma(Aluno turma[], int n) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += turma[i].nota;
    }
    return soma / n;
}
```

**Q10.**
```c
Aluno melhor_aluno(Aluno turma[], int n) {
    Aluno melhor = turma[0];
    for (int i = 1; i < n; i++) {
        if (turma[i].nota > melhor.nota) {
            melhor = turma[i];
        }
    }
    return melhor;
}
```

---

## Parte 3 — Rastreio de recursão

**Q11.** `10`
`f(4) = 4 + f(3) = 4+3+2+1+0 = 10`.

**Q12.** `1 2 3`
A chamada `g(n-1)` acontece **antes** do `printf`, então imprime na volta da
recursão (do menor pro maior). Se trocar a ordem (printf antes da chamada),
a saída vira `3 2 1`.

**Q13.** `15` chamadas.
Contando a árvore: `C(0)=C(1)=1` e `C(n)=1+C(n-1)+C(n-2)`.
`C(2)=3, C(3)=5, C(4)=9, C(5)=15`.
(É por isso que Fibonacci recursivo "puro" é lento — explode em chamadas.)

**Q14.** `12`
É o **MDC** (máximo divisor comum) por Euclides.
`misterio(48,36) → misterio(36,12) → misterio(12,0) → 12`.

---

## Parte 4 — Recursão (escreva)

**Q15.**
```c
int soma(int n) {
    if (n == 0) return 0;          // caso base
    return n + soma(n - 1);        // passo
}
```

**Q16.**
```c
int potencia(int base, int exp) {
    if (exp == 0) return 1;
    return base * potencia(base, exp - 1);
}
```

**Q17.**
```c
int soma_digitos(int n) {
    if (n == 0) return 0;
    return (n % 10) + soma_digitos(n / 10);
}
```

**Q18.**
```c
int qtd_digitos(int n) {
    if (n < 10) return 1;
    return 1 + qtd_digitos(n / 10);
}
```

**Q19.**
```c
void imprime_invertido(int n) {
    printf("%d ", n % 10);
    if (n / 10 > 0) imprime_invertido(n / 10);
}
```

**Q20.**
```c
int soma_vetor(int v[], int n) {
    if (n == 0) return 0;
    return v[n - 1] + soma_vetor(v, n - 1);
}
```

**Q21.**
```c
int contem(int v[], int n, int alvo) {
    if (n == 0) return 0;
    if (v[n - 1] == alvo) return 1;
    return contem(v, n - 1, alvo);
}
```

---

## Parte 5 — Struct + recursão

**Q22.**
```c
int fatorial(int n) {
    if (n <= 1) return 1;
    return n * fatorial(n - 1);
}

Calculo calcular_fatorial(int n) {
    Calculo c;
    c.n = n;
    c.resultado = fatorial(n);
    return c;
}
```

**Q23.**
```c
float maior_nota(Aluno turma[], int n) {
    if (n == 1) return turma[0].nota;          // caso base
    float m = maior_nota(turma, n - 1);
    if (turma[n - 1].nota > m) return turma[n - 1].nota;
    return m;
}
```

**Q24.**
```c
float soma_saldos(Conta contas[], int n) {
    if (n == 0) return 0;
    return contas[n - 1].saldo + soma_saldos(contas, n - 1);
}
```

---

## Desafios

**D1.**
```c
int inverte_aux(int n, int acc) {
    if (n == 0) return acc;
    return inverte_aux(n / 10, acc * 10 + n % 10);
}
int eh_palindromo(int n) {
    return n == inverte_aux(n, 0);   // 1 = é, 0 = não é
}
```

**D2.**
```c
void hanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 1) {
        printf("Mova disco de %c para %c\n", origem, destino);
        return;
    }
    hanoi(n - 1, origem, auxiliar, destino);
    printf("Mova disco de %c para %c\n", origem, destino);
    hanoi(n - 1, auxiliar, destino, origem);
}
```

**D3.**
```c
float dist2(Ponto p) {
    return p.x * p.x + p.y * p.y;   // distância ao quadrado (basta pra comparar)
}
Ponto mais_distante(Ponto v[], int n) {
    if (n == 1) return v[0];
    Ponto p = mais_distante(v, n - 1);
    if (dist2(v[n - 1]) > dist2(p)) return v[n - 1];
    return p;
}
```
