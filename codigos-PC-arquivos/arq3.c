#Solicitar um nome e salvar caractere por caractere em "nome.txt"
#include <stdio.h>

int main() {
    FILE *arquivo;
    char nome[100];
    int i;

    // Solicita a entrada do usuário
    printf("Digite um nome: ");
    fgets(nome, sizeof(nome), stdin);

    // Abre o arquivo para escrita
    arquivo = fopen("nome.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    // Escreve caractere por caractere no arquivo
    for (i = 0; nome[i] != '\0'; i++) {
        fputc(nome[i], arquivo);
    }

    // Fecha o arquivo
    fclose(arquivo);

    printf("Nome salvo em 'nome.txt' com sucesso!\n");

    return 0;
}
