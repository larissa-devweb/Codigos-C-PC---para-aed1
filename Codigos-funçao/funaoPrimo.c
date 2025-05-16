#include <stdio.h>

// Função que verifica se um número é primo
int ehPrimo(int n) {
    if (n < 2) return 0; // Números menores que 2 não são primos
    if (n == 2) return 1; // O número 2 é primo

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0; // Se for divisível por algum número além de 1 e ele mesmo, não é primo
        }
    }
    return 1; // Se não encontrou nenhum divisor, é primo
}

int main() {
    int n1;
    while (1) {
        printf("Digite o número (-1 para sair): ");
        scanf("%d", &n1);

        if (n1 == -1) {
            break;
        }

        if (ehprimo(n1)) {
            printf("%d é primo.\n", n1);
        } else {
            printf("%d não é primo.\n", n1);
        }
    }

    return 0;
}
