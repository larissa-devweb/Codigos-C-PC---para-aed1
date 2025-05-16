//lr e imprimir caracter a caracter de nomes.txt
#include <stdio.h>

int main() {
    FILE *arquivo;
    char ch;

    // Abre o arquivo para leitura
    arquivo = fopen("nome.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    // Lê caractere por caractere e imprime na tela
    while ((ch = fgetc(arquivo)) != EOF) {
        putchar(ch);
    }

    // Fecha o arquivo
    fclose(arquivo);

    return 0;
}
