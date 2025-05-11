#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cliente {
    char nome[100];
};
void cadastrarClientes(struct cliente *clientes, int tamanho);
void salvarClientes(struct cliente *clientes, int tamanho);

int main() {
    int tamanho, i;
    int op = -1;
    // FILE *arquivo;

    printf("Quantos clientes deseja alocar? ");
    scanf("%d", &tamanho);
    getchar();

    struct cliente *clientes = (struct cliente*) malloc(sizeof(struct cliente) * tamanho);
    if (clientes == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }
//se eu quiser só chamar funçao SEM WHILE/OPÇOES, BASTA APAGAR WHILE TODO E DEIXAR  cadastrarClientes(clientes, tamanho);

    while (op != 2) {
        printf("\nDigite a opção:\n");
        printf("1. Cadastrar\n");
        printf("2. Salvar arquivo e sair\n");
        printf("Opção: ");
        scanf("%d", &op);
        getchar();

        if (op == 1) {
            cadastrarClientes(clientes, tamanho);  // Passagem por referência
        } else if (op == 2) {
            salvarClientes(clientes, tamanho);  // Passagem por referência ou só coloca o arquivo aqui mesmo
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }
    free(clientes);  // Libera a memória alocada
    return 0;
}

void cadastrarClientes(struct cliente *clientes, int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("Nome: ");
        fgets(clientes[i].nome, 100, stdin);
    }
}

// Função para salvar os dados dos clientes em um arquivo
void salvarClientes(struct cliente *clientes, int tamanho) {
    FILE *arquivo = fopen("clientes.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "Nome: %s\n", clientes[i].nome);
    }
    fclose(arquivo);
    printf("Dados salvos no arquivo 'clientes.txt'.\n");
}
