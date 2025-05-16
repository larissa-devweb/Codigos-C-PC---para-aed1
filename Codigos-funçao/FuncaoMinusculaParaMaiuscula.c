#include <stdio.h>
#include <ctype.h> // Biblioteca necessária para funções de manipulação de caracteres


// Função para converter uma string para maiúsculas
void maiusculas(char str[]) {
    int i;
    for (i = 0; str[i] != '\0'; i++) { // Itera sobre cada caractere da string
        str[i] = toupper(str[i]); // Converte o caractere para maiúscula
    }
    printf("String em maiúsculas: %s\n", str); // Agora sim, exibe a string convertida
}

int main() {
    char str[101]; // Declaração de uma string de até 100 caracteres

    printf("Digite uma string com letras minúsculas: ");
    fgets(str, 101, stdin); // Lê a string do usuário



    maiusculas(str); // Chama a função para converter a string

    return 0;
}
//SEM FUNCAO:
/*int main() {
    char str[101]; // Declaração de uma string de até 100 caracteres
    int i;

    printf("Digite uma string com letras minúsculas: ");
    fgets(str, 101, stdin); // Lê a string do usuário

    for (i = 0; str[i] != '\0'; i++) { // Itera sobre cada caractere da string
        str[i] = toupper(str[i]); // Converte o caractere para maiúscula, se for minúscula
    }

    printf("String em maiúsculas: %s\n", str); // Exibe a string convertida

    return 0;
}*/
