/*
2. Escreva um programa que contenha duas variáveis inteiras.
Compare seus endereços e exiba o maior endereço.
*/

#include <stdio.h>

int main() {
    int x = 10;
    int y = 20;

    // Mostra os endereços das variáveis
    printf("Endereço de x: %p\n", &x);
    printf("Endereço de y: %p\n", &y);

    // Compara os endereços e mostra qual é maior
    if (&x > &y)
        printf("O maior endereço é o de x\n");
    else
        printf("O maior endereço é o de y\n");

    return 0;
}
