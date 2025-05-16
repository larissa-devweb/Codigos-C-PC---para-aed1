#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor; // Ponteiro para o vetor de inteiros
    int tamanho;      // O número de elementos que vamos alocar
    int i;

    printf("Quantos numeros alocar? ");
    scanf("%d", &tamanho);

    vetor = (int *)malloc(n * sizeof(int));

    if (vetor == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    printf("Digite %d numeros:\n", tamanho);
    for (i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("Os números digitados são:\n");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]); // Imprime cada número armazenado no vetor
    }
    printf("\n");

    free(vetor);

    return 0;
}
