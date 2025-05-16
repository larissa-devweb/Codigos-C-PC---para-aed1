/*Contar o número de caracteres em uma string*/
#include <stdio.h>
#include <string.h>

int contarCaracteres(char str[]) {
    return strlen(str);
}

int main() {
    char str[30];
    int comprimento;

    printf ("digite string:");
    fgets (s,30,stdin);

        comprimento = strlen(str) - 1;
        printf ("string tem : %d", comprimento);


    return 0;
}
