/*Exibir caracteres nas posições pares de uma string*/
#include <stdio.h>
#include <string.h>

void pares(char str[]) {
     int i;
    printf("Caracteres nas posições pares: ");
// Itera sobre a string, começando da posição 1 (segunda posição)
//se fosse IMPAR, seria i = 1, apenas isto.
   for (i = 0; str[i] !='\0'; i+=2){
      printf("%c", str[i]); // Exibe apenas os caracteres nas posições pares
   }
}

int main() {
    char str[30];

     printf ("digite string:");
    fgets (str,30,stdin);

    pares(str);

    return 0;
}
