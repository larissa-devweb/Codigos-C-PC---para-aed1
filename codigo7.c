/*
1. Crie um programa que:
(a) Aloque dinamicamente um array de 5 números inteiros,
(b) Peça para o usuário digitar os 5 números no espaço alocado,
(c) Mostre na tela os 5 números,
(d) Libere a memória alocada.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor = (int *)malloc(sizeof(int) * 5);

    if (vetor == NULL) {
        printf("Erro de alocação!\n");
        return 1;
    }

    printf("Digite 5 números inteiros:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("Você digitou:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);  // Liberação da memória
    return 0;
}
