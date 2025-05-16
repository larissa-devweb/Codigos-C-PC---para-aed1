#include <stdio.h>

int main() {
    int num, i;

    // Lê o número
    printf("Digite um número inteiro: ");
    scanf("%d", &num);

    // Imprime os divisores
    printf("Divisores de %d: ", num);
    for (i = 1; i <= num; i++) {
        if (num % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
