#include <stdio.h>
#include <stdbool.h> // Para usar o tipo bool

// Função para verificar se um número é primo
bool ehPrimo(int numero) {
    // Números menores ou iguais a 1 não são primos
    if (numero <= 1) return false;

    // Verifica divisores de 2 até a raiz quadrada do número
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return false; // Não é primo se for divisível por i
        }
    }

    return true; // Se não encontrou divisores, é primo
}

// Função principal para testar a verificação de número primo
int main() {
    int numero;

    // Solicita ao usuário que insira um número
    printf("Digite um número para verificar se é primo: ");
    scanf("%d", &numero); // Lê o número do usuário

    // Verifica se o número é primo e imprime a mensagem apropriada
    if (ehPrimo(numero)) {
        printf("%d é um número primo.\n", numero);
    } else {
        printf("%d não é um número primo.\n", numero);
    }

    return 0; // Retorna 0 para indicar sucesso
}
