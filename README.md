# Aulas de C

Repositório de estudos da linguagem C, reunindo exercícios e anotações feitas durante:

- A disciplina **PDS I (Programação e Desenvolvimento de Software I)** com o **Prof. Adriano Veloso** na **UFMG**.
- O curso **Algoritmos e Lógica de Programação — O Curso COMPLETO** (Udemy).

O objetivo aqui é praticar os fundamentos da linguagem (entrada/saída, condicionais, laços, vetores, matrizes, recursão, arquivos e funções) resolvendo as listas da disciplina e os exercícios propostos no curso.

## Estrutura

```
.
├── input_output/              # printf, scanf, cálculos simples
│   ├── idades.c
│   ├── juros.c
│   ├── retangulo.c
│   ├── terreno.c
│   └── media_de_alturas/      # Exercícios sobre média e entrada/saída
│       ├── media_de_alturas.c
│       └── media_de_alturas_malloc.c
├── condicional/               # if/else, for, while
│   ├── if/                    # if / else / else if
│   ├── para/                  # laço for
│   └── while/                 # laço while
├── vetores/                   # vetores (arrays) — soma, busca, etc.
├── matriz/                    # matrizes bidimensionais
├── arquivo/                   # leitura e escrita de arquivos com FILE*
│   └── arquivo_numeros/       # Exercícios de I/O com arquivos
│       └── leitura_escrita_arquivo.c
├── recursiva/                 # funções recursivas
└── PDS I adriano/             # listas da disciplina do prof. Adriano Veloso
    ├── lista_2_Procedimentos_e_Funcoes.pdf
    ├── lista_3_If_e_Predicados.pdf
    ├── lista_5_Repeticao.pdf
    ├── lista_7_Vetores.pdf
    ├── lista_9_Matrizes.pdf
    ├── list/                  # resoluções (lista_2.c, lista_3.c, lista_5.c)
    └── list_2/                # resoluções de funções, vetores e matrizes
```

Cada pasta tem (ou pode ter) uma subpasta `output/` com os binários compilados — não é necessário versioná-los, mas estão presentes durante o desenvolvimento.

## Conteúdo por tópico

| Pasta | Tópicos praticados |
|-------|---------------------|
| [input_output/](input_output/) | leitura e escrita formatada, cálculo de juros, área de terreno, retângulo, idades |
| [input_output/media_de_alturas/](input_output/media_de_alturas/) | média aritmética com validação de intervalo, alocação dinâmica com `malloc` e `realloc` |
| [condicional/if/](condicional/if/) | Bhaskara, maior/menor/média, notas, decisões com `if/else` |
| [condicional/para/](condicional/para/) | tabuada, soma de ímpares com `for` |
| [condicional/while/](condicional/while/) | sequência crescente, média com `while` |
| [vetores/](vetores/) | soma de vetor, contagem de negativos, alturas |
| [matriz/](matriz/) | extração da diagonal principal |
| [arquivo/](arquivo/) | criação, escrita e leitura de arquivos texto |
| [arquivo/arquivo_numeros/](arquivo/arquivo_numeros/) | leitura e escrita de números em arquivos com `fprintf` e `fscanf` |
| [recursiva/](recursiva/) | funções recursivas |
| [PDS I adriano/list_2/](PDS%20I%20adriano/list_2/) | funções: criar arranjo, ler matriz, operações com vetores e matrizes (média, identidade, transposta, simétrica, soma e multiplicação) |

## Como compilar e executar

Os exemplos foram desenvolvidos no Linux com o `gcc`. Para compilar e rodar qualquer arquivo:

```bash
gcc caminho/para/arquivo.c -o programa -lm
./programa
```

A flag `-lm` é necessária quando o programa usa `math.h` (por exemplo, `sqrt`, `pow`).

Exemplo:

```bash
gcc condicional/if/baskara.c -o baskara -lm
./baskara
```

## Referências

- Prof. Adriano Veloso — PDS I, DCC/UFMG.
- Curso *Algoritmos e Lógica de Programação — O Curso COMPLETO* (Udemy).
