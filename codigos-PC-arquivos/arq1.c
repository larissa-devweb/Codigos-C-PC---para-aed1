//salvar frase m arquivo
#include <stdio.h>

int main() {
    FILE *arquivo;
    char frase[256];

    // Solicita a entrada do usuário
    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    // Abre o arquivo para escrita
    arquivo = fopen("frase.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    // Escreve a frase no arquivo
    fprintf(arquivo, "%s", frase);

    // Fecha o arquivo
    fclose(arquivo);

    printf("Frase salva em 'frase.txt' com sucesso!\n");

    return 0;
}
