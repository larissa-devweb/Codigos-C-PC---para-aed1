//Dada uma string sconsistindo de palavras e espa�os, retorna o comprimento da �ltima palavra na string.
#include <stdio.h>
#include <string.h>

// Fun��o que calcula o tamanho da �ltima palavra
int tamanhoUltimaPalavra(char *frase) {
    int tamanho = 0;
    int i = strlen(frase) - 1; // Come�a do �ltimo caractere

    // Pula os espa�os em branco no final da frase
    while (i >= 0 && frase[i] == ' ') {
        i--;
    }

    // Conta as letras da �ltima palavra
    while (i >= 0 && frase[i] != ' ') {
        tamanho++;
        i--;
    }

    return tamanho;
}

int main() {
    char texto1[] = "Bom dia mundo";
    char texto2[] = "   C � uma linguagem poderosa   ";

    printf("Frase: '%s'\n", texto1);
    printf("Tamanho da �ltima palavra: %d\n\n", tamanhoUltimaPalavra(texto1));

    printf("Frase: '%s'\n", texto2);
    printf("Tamanho da �ltima palavra: %d\n\n", tamanhoUltimaPalavra(texto2));


    return 0;
}
