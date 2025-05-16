#include <stdio.h>
#include <stdbool.h>

// Função que verifica se um número é primo
bool ehPrimo(int n) {
    if (n <= 1) {
        return false; // Números menores ou iguais a 1 não são primos
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false; // Se n é divisível por i, então não é primo
        }
    }
    return true; // Se não encontrou divisor, é primo
}

int main() {
    int num;
    printf("Digite um número: ");
    scanf("%d", &num);

    if (ehPrimo(num)) {
        printf("%d é um número primo.\n", num);
    } else {
        printf("%d não é um número primo.\n", num);
    }

    return 0;
}
