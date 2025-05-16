/*Faça um algoritmo que defina uma struct a qual contenha: o nome do aluno, a identificação e uma nota. Logo após solicite ao usuário que seja informa o nome, a identificação e a nota e ao final mostre essas informações*/

#include <stdio.h>

int potencia(int base, int expoente);
int main(){
    int base, expoente, resultado;
    printf ("digite base: ");
    scanf ("%d", &base);
    printf ("digite expoente: ");
    scanf ("%d", &expoente);
 resultado = potencia( base,expoente);
     printf ("resultado : %d ",resultado);

     return 0;
}
int potencia(int base, int expoente){
    int resultado = 1, i = 0;
    for (i = 0; i < expoente; i++) {
        resultado *= base;
    }
    return resultado;
}
