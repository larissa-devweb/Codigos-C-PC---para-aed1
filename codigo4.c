/*
5. Fa�a um programa que leia dois valores inteiros e chame uma fun��o que
receba estes 2 valores de entrada e retorne o maior valor na primeira
vari�vel e o menor valor na segunda vari�vel. Escreva o conte�do das 2
vari�veis na tela.
*/

#include <stdio.h>

void ordenar(int *a, int *b) {
    if (*a < *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main() {
    int x, y;

    printf("Digite dois valores inteiros: ");
    scanf("%d %d", &x, &y);

    ordenar(&x, &y);

    printf("Maior: %d, Menor: %d\n", x, y);

    return 0;
}
