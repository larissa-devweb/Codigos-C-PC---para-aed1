/*
3. Faça um programa que leia do usuário o tamanho de um vetor a ser lido
e faça a alocação dinâmica de memória. Em seguida, leia do usuário seus
valores e mostre quantos dos números são pares e quantos são ímpares.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, pares = 0, impares = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int *vetor = (int *)malloc(n * sizeof(int));
    if (vetor == NULL) {
        printf("Erro de alocação de memória!\n");
        return 1;
    }

    printf("Digite os %d valores:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
        if (vetor[i] % 2 == 0)
            pares++;
        else
            impares++;
    }

    printf("Pares: %d\nÍmpares: %d\n", pares, impares);

    free(vetor);
    return 0;
}
