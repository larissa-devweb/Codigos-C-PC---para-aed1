/*
14. Crie uma função que receba dois parâmetros: um array e um valor do mesmo tipo do array.
A função deverá preencher os elementos de array com esse valor.
Não utilize índices para percorrer o array, apenas aritmética de ponteiros.
*/

#include <stdio.h>
//v de vetor
void preencher(int *v, int tamanho, int valor) {
    int *p = v;
    while (p < v + tamanho) {
        *p = valor;
        p++;
    }
}

int main() {
    int vetor[10];
    preencher(vetor, 10, 7);

    for (int i = 0; i < 10; i++)
        printf("%d ", vetor[i]);

    return 0;
}
