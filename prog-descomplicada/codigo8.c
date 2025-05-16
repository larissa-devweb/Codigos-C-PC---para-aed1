/*
3. Fa�a um programa que leia do usu�rio o tamanho de um vetor a ser lido
e fa�a a aloca��o din�mica de mem�ria. Em seguida, leia do usu�rio seus
valores e mostre quantos dos n�meros s�o pares e quantos s�o �mpares.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, pares = 0, impares = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int *vetor = (int *)malloc(n * sizeof(int));
    if (vetor == NULL) {
        printf("Erro de aloca��o de mem�ria!\n");
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

    printf("Pares: %d\n�mpares: %d\n", pares, impares);

    free(vetor);
    return 0;
}
