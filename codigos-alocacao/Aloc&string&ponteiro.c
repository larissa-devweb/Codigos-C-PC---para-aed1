#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int tamanho = 1;

    char *nome = (char *)malloc(sizeof(char)* tamanho);
    char *sobrenome = (char *)malloc(sizeof(char) * tamanho);

    if (nome == NULL || sobrenome == NULL) {
        printf("Erro na aloca��o de mem�ria.\n");
        return 1;
    }

    printf("Digite seu nome: ");
    fgets(nome, 50, stdin);

    printf("Digite seu sobrenome: ");
    fgets(sobrenome, 50, stdin);

    char *nome_completo = (char *)malloc((strlen(nome) + strlen(sobrenome) + 2) * tamanho);

    if (nome_completo == NULL) {
        printf("Erro na aloca��o de mem�ria.\n");
        free(nome);
        free(sobrenome);
        return 1;
    }

    strcpy(nome_completo, nome);
    strcat(nome_completo, " ");
    strcat(nome_completo, sobrenome);

    printf("Nome completo: %s\n", nome_completo);

    // Libera toda a mem�ria alocada
    free(nome);
    free(sobrenome);
    free(nome_completo);

    return 0;
}
