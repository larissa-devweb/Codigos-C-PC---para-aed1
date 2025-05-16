/*
15. Crie uma função que receba como parâmetro um array e o imprima.
Não utilize índices para percorrer o array, apenas aritmética de ponteiros.
*/

#include <stdio.h>

void imprimir(int *vet, int tamanho) {
    int *p = vet;
    while (p < vet + tamanho) {
        printf("%d ", *p);
        p++;
    }
    printf("\n");
}

int main() {
    int vetor[5] = {1, 2, 3, 4, 5};
    imprimir(vetor, 5);

    return 0;
}
