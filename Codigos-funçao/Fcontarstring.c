#include <stdio.h>

int contarCaracteres(const char *str);

#include <stdio.h>

int contarCaracteres(const char *str);

int main() {
    char str[30];
    int comprimento;

    // Solicita a string ao usu�rio
    printf("Digite uma string: ");
    fgets(str, 30, stdin);

    // Remover o '\n' do fgets, se presente
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }

    // Chama a fun��o para contar caracteres
    comprimento = contarCaracteres(str);

    // Exibe o resultado
    printf("A string tem %d caracteres.\n", comprimento);

    return 0;
}

// Fun��o para contar caracteres em uma string
int contarCaracteres(const char *str) {
    int contador = 0;
    while (*str != '\0') {
        contador++;
        str++; // Avan�a o ponteiro para o pr�ximo caractere
    }
    return contador;
}
