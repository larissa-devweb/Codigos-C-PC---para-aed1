/*
4. Faça um programa que leia 2 valores inteiros e chame uma função que
receba estas 2 variáveis e troque o seu conteúdo, ou seja, esta função
é chamada passando duas variáveis A e B por exemplo e, após a execução
da função, A conterá o valor de B e B terá o valor de A.
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

    printf("Após a troca: x = %d, y = %d\n", n1, n2);

    return 0;
}
