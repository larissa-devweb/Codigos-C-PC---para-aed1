#include <stdio.h>
#include <stdlib.h>

// Função para calcular o máximo valor possível
long long somaMaxima(int numeros[], int tamanho, int k) {
    long long somaTotal = 0;      // Soma total dos valores dos nós
    int contadorAumenta = 0;      // Conta quantos nós ficam maiores ao aplicar XOR k
    int menorDiferenca = 2147483647; // Define o maior inteiro possível (substitui __INT_MAX__)

    // Percorre todos os nós
    for (int i = 0; i < tamanho; i++) {
        int valorXor = numeros[i] ^ k;   // Faz a operação XOR com k
        int diferenca = valorXor - numeros[i]; // Calcula a diferença entre o valor novo e o antigo

        // Verifica se aplicar XOR aumenta o valor do nó
        if (diferenca > 0) {
            somaTotal += valorXor;   // Soma o valor alterado
            contadorAumenta++;       // Conta esse aumento
        } else {
            somaTotal += numeros[i]; // Se não aumenta, mantém o valor original
        }

        // Verifica a menor diferença absoluta (para caso precise ajustar depois)
        if (abs(diferenca) < menorDiferenca) {
            menorDiferenca = abs(diferenca);
        }
    }

    // Se o número de aumentos for par, soma já é máxima
    if (contadorAumenta % 2 == 0) {
        return somaTotal;
    }

    // Se for ímpar, precisamos desfazer o menor aumento para transformar em par
    return somaTotal - menorDiferenca;
}

int main() {
    // Exemplo da questão
    int numeros[] = {1, 2, 1};   // Valores dos nós
    int tamanho = 3;             // Quantidade de nós
    int k = 3;                   // Valor de k (XOR)

    // Chama a função e imprime o resultado
    long long resultado = somaMaxima(numeros, tamanho, k);
    printf("Soma máxima: %lld\n", resultado);

    return 0;
}
