#include <stdio.h>
#include <ctype.h> // Biblioteca necess�ria para fun��es de manipula��o de caracteres


// Fun��o para converter uma string para mai�sculas
void maiusculas(char str[]) {
    int i;
    for (i = 0; str[i] != '\0'; i++) { // Itera sobre cada caractere da string
        str[i] = toupper(str[i]); // Converte o caractere para mai�scula
    }
    printf("String em mai�sculas: %s\n", str); // Agora sim, exibe a string convertida
}

int main() {
    char str[101]; // Declara��o de uma string de at� 100 caracteres

    printf("Digite uma string com letras min�sculas: ");
    fgets(str, 101, stdin); // L� a string do usu�rio



    maiusculas(str); // Chama a fun��o para converter a string

    return 0;
}
//SEM FUNCAO:
/*int main() {
    char str[101]; // Declara��o de uma string de at� 100 caracteres
    int i;

    printf("Digite uma string com letras min�sculas: ");
    fgets(str, 101, stdin); // L� a string do usu�rio

    for (i = 0; str[i] != '\0'; i++) { // Itera sobre cada caractere da string
        str[i] = toupper(str[i]); // Converte o caractere para mai�scula, se for min�scula
    }

    printf("String em mai�sculas: %s\n", str); // Exibe a string convertida

    return 0;
}*/
