#include <stdio.h>

int contarCaracteres(const char *str);
int main() {
    char str[30];
    int comprimento;

    // Solicita a string ao usuário
    printf("Digite uma string: ");
    fgets(str, 30, stdin);

    // Chama a função para contar caracteres
    comprimento = contarCaracteres(str);

    // Exibe o resultado
    printf("A string tem %d caracteres.\n", comprimento);

    return 0;
}
// Função para contar caracteres em uma string
int contarCaracteres(const char *str) {
    int contador = 0;
    while (*str != '\0') {
        contador++;
        str++; // Avança o ponteiro para o próximo caractere
    }
    return contador;
}
