#include <stdio.h>

// Fun��o que verifica se um n�mero � primo
int ehPrimo(int n) {
    if (n < 2) return 0; // N�meros menores que 2 n�o s�o primos
    if (n == 2) return 1; // O n�mero 2 � primo

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0; // Se for divis�vel por algum n�mero al�m de 1 e ele mesmo, n�o � primo
        }
    }
    return 1; // Se n�o encontrou nenhum divisor, � primo
}

int main() {
    int n1;
    while (1) {
        printf("Digite o n�mero (-1 para sair): ");
        scanf("%d", &n1);

        if (n1 == -1) {
            break;
        }

        if (ehprimo(n1)) {
            printf("%d � primo.\n", n1);
        } else {
            printf("%d n�o � primo.\n", n1);
        }
    }

    return 0;
}
