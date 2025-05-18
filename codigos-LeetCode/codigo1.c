#include <stdio.h>
#include <string.h> // Para usar a função strlen()

// Função que calcula o tamanho da última palavra
int tamanhoUltimaPalavra(char *frase) {
    int tamanho = 0;
    int i = strlen(frase) - 1; // Começa do último caractere
    
    // Pula os espaços em branco no final da frase
    while (i >= 0 && frase[i] == ' ') {
        i--;
    }
    
    // Conta as letras da última palavra
    while (i >= 0 && frase[i] != ' ') {
        tamanho++;
        i--;
    }
    
    return tamanho;
}

int main() {
    char texto1[] = "Bom dia mundo";
    char texto2[] = "   C é uma linguagem poderosa   ";
    char texto3[] = "Programar em C";
    
    printf("Frase: '%s'\n", texto1);
    printf("Tamanho da última palavra: %d\n\n", tamanhoUltimaPalavra(texto1));
    
    printf("Frase: '%s'\n", texto2);
    printf("Tamanho da última palavra: %d\n\n", tamanhoUltimaPalavra(texto2));
    
    printf("Frase: '%s'\n", texto3);
    printf("Tamanho da última palavra: %d\n", tamanhoUltimaPalavra(texto3));
    
    return 0;
}