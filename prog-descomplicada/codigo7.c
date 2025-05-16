/*
1. Crie um programa que:
(a) Aloque dinamicamente um array de 5 n�meros inteiros,
(b) Pe�a para o usu�rio digitar os 5 n�meros no espa�o alocado,
(c) Mostre na tela os 5 n�meros,
(d) Libere a mem�ria alocada.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor = (int *)malloc(sizeof(int) * 5);

    if (vetor == NULL) {
        printf("Erro de aloca��o!\n");
        return 1;
    }

    printf("Digite 5 n�meros inteiros:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("Voc� digitou:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);  // Libera��o da mem�ria
    return 0;
}
