/*
1. Escreva um programa que declare um inteiro, um real e um char,
e ponteiros para inteiro, real, e char.
Associe as vari�veis aos ponteiros (use &).
Modifique os valores de cada vari�vel usando os ponteiros.
Imprima os valores das vari�veis antes e ap�s a modifica��o.
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
