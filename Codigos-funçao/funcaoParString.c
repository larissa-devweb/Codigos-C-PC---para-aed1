/*Exibir caracteres nas posi��es pares de uma string*/
#include <stdio.h>
#include <string.h>

void pares(char str[]) {
     int i;
    printf("Caracteres nas posi��es pares: ");
// Itera sobre a string, come�ando da posi��o 1 (segunda posi��o)
//se fosse IMPAR, seria i = 1, apenas isto.
   for (i = 0; str[i] !='\0'; i+=2){
      printf("%c", str[i]); // Exibe apenas os caracteres nas posi��es pares
   }
}

int main() {
    char str[30];

     printf ("digite string:");
    fgets (str,30,stdin);

    pares(str);

    return 0;
}
