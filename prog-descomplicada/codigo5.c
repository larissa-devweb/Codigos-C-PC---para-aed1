/*
14. Crie uma fun��o que receba dois par�metros: um array e um valor do mesmo tipo do array.
A fun��o dever� preencher os elementos de array com esse valor.
N�o utilize �ndices para percorrer o array, apenas aritm�tica de ponteiros.
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
