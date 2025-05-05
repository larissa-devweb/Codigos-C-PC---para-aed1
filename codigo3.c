/*
4. Fa�a um programa que leia 2 valores inteiros e chame uma fun��o que
receba estas 2 vari�veis e troque o seu conte�do, ou seja, esta fun��o
� chamada passando duas vari�veis A e B por exemplo e, ap�s a execu��o
da fun��o, A conter� o valor de B e B ter� o valor de A.
*/

#include <stdio.h>

void trocar(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int n1, n2;

    printf("Digite dois valores inteiros: ");
    scanf("%d %d", &n1, &n2);

    trocar(&n1, &n2);

    printf("Ap�s a troca: x = %d, y = %d\n", n1, n2);

    return 0;
}
