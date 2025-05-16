/*
1. Escreva um programa que declare um inteiro, um real e um char,
e ponteiros para inteiro, real, e char.
Associe as variáveis aos ponteiros (use &).
Modifique os valores de cada variável usando os ponteiros.
Imprima os valores das variáveis antes e após a modificação.
*/

#include <stdio.h>

int main() {
    int inteiro = 10;
    float real = 5.5;
    char letra = 'L';

    int *pInteiro = &inteiro;
    float *pReal = &real;
    char *pLetra = &letra;

    printf("Antes:\nInteiro = %d\nReal = %.2f\nLetra = %c\n", inteiro, real, letra);

    *pInteiro = 20;
    *pReal = 10.5;
    *pLetra = 'Z';

    printf("Depois:\nInteiro = %d\nReal = %.2f\nLetra = %c\n", inteiro, real, letra);

    return 0;
}
