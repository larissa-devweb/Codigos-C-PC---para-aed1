#include <stdio.h>
#include <stdbool.h>

// Fun��o que verifica se um n�mero � primo
bool ehPrimo(int n) {
    if (n <= 1) {
        return false; // N�meros menores ou iguais a 1 n�o s�o primos
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false; // Se n � divis�vel por i, ent�o n�o � primo
        }
    }
    return true; // Se n�o encontrou divisor, � primo
}

int main() {
    int num;
    printf("Digite um n�mero: ");
    scanf("%d", &num);

    if (ehPrimo(num)) {
        printf("%d � um n�mero primo.\n", num);
    } else {
        printf("%d n�o � um n�mero primo.\n", num);
    }

    return 0;
}
