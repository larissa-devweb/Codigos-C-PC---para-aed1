/*
2. Escreva um programa que contenha duas vari�veis inteiras.
Compare seus endere�os e exiba o maior endere�o.
*/

#include <stdio.h>

int main() {
    int x = 10;
    int y = 20;

    // Mostra os endere�os das vari�veis
    printf("Endere�o de x: %p\n", &x);
    printf("Endere�o de y: %p\n", &y);

    // Compara os endere�os e mostra qual � maior
    if (&x > &y)
        printf("O maior endere�o � o de x\n");
    else
        printf("O maior endere�o � o de y\n");

    return 0;
}
