#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cliente {
    char nome[100];
};

void cadastrarClientes(struct cliente **clientes, int *tamanho_atual, int *quantidade);
void salvarClientes(struct cliente *clientes, int quantidade);

int main() {
    int tamanho_inicial;
    int quantidade = 0;
    int op = -1;

    printf("Quantos clientes deseja alocar inicialmente? ");
    scanf("%d", &tamanho_inicial);
    getchar();

    struct cliente *clientes = (struct cliente*)malloc(sizeof(struct cliente) * tamanho_inicial);
    if (clientes == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }

    while (op != 2) {
        printf("\nDigite a opção:\n");
        printf("1. Cadastrar\n");
        printf("2. Salvar arquivo e sair\n");
        printf("Opção: ");
        scanf("%d", &op);
        getchar();

        if (op == 1) {
            cadastrarClientes(&clientes, &tamanho_inicial, &quantidade);
        } else if (op == 2) {
            salvarClientes(clientes, quantidade);
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    free(clientes);
    return 0;
}

void cadastrarClientes(struct cliente **clientes, int *tamanho_atual, int *quantidade) {
    char continuar;

    do {
        if (*quantidade >= *tamanho_atual) {
            // Redimensiona o array usando realloc
            int novoTamanho = *tamanho_atual * 2; // Dobra o tamanho
            struct cliente *temp = (struct cliente*)realloc(*clientes, sizeof(struct cliente) * novoTamanho);

            if (temp == NULL) {
                printf("Erro ao realocar memória.\n");
                exit(1);
            }

            *clientes = temp;
            *tamanho_atual = novoTamanho;
            printf("Array redimensionado para %d clientes\n", novoTamanho);
        }

        printf("Nome: ");
        fgets((*clientes)[*quantidade].nome, sizeof((*clientes)[*quantidade].nome), stdin);
        (*quantidade)++;

        printf("Deseja cadastrar outro cliente? (s/n): ");
        scanf(" %c", &continuar);
        getchar();
    } while (continuar == 's' || continuar == 'S');
}

void salvarClientes(struct cliente *clientes, int quantidade) {
    FILE *arquivo = fopen("clientes.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "Nome: %s", clientes[i].nome); // Já inclui \n do fgets
    }

    fclose(arquivo);
    printf("Dados salvos no arquivo 'clientes.txt'.\n");
}
