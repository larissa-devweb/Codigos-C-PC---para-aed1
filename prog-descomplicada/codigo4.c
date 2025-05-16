/*
5. Faça um programa que leia dois valores inteiros e chame uma função que
receba estes 2 valores de entrada e retorne o maior valor na primeira
variável e o menor valor na segunda variável. Escreva o conteúdo das 2
variáveis na tela.
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
