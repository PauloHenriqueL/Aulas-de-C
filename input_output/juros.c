#include <stdio.h>

int main() {
    
    double saldo = 500.00;       // Mês 1: Abertura da conta com depósito
    double taxa_juros = 0.01;    // Rendimento de 1% ao mês

    // Processamento do Mês 2
    saldo += saldo * taxa_juros; // Rendimento sobre o saldo do Mês 1
    saldo += 200.00;             // Novo depósito do Mês 2

    // Processamento do Mês 3
    saldo += saldo * taxa_juros; // Rendimento sobre o saldo do Mês 2
    saldo -= 50.00;              // Saque do Mês 3

    // Processamento do Mês 4
    saldo += saldo * taxa_juros; // Rendimento sobre o saldo do Mês 3

    // Saída do resultado
    printf("O saldo na conta poupanca no quarto mes sera de: R$ %.2f\n", saldo);

    return 0;
}