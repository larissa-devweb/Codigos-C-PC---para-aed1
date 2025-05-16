/*
2. Considere um cadastro de produtos de um estoque, com as seguintes informações:
(a) Defina uma estrutura, denominada produto, com:
    - Código de identificação (int)
    - Nome do produto (até 50 caracteres)
    - Quantidade disponível no estoque (int)
    - Preço de venda (float)

(b) Crie um conjunto de N produtos (N é fornecido pelo usuário)
    - Peça ao usuário para digitar as informações de cada produto

(c) Encontre o produto com o maior preço de venda

(d) Encontre o produto com a maior quantidade disponível no estoque
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 51  // 50 + 1 para \0

typedef struct {
    int codigo;
    char nome[TAM_NOME];
    int quantidade;
    float preco;
} Produto;

int main() {
    int n, i;

    printf("Digite quantidade de produtos: ");
    scanf("%d", &n);

    Produto *estoque = (Produto *)malloc(sizeof(Produto) * n);
    if (estoque == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Leitura dos produtos
    for (i = 0; i < n; i++) {
        printf("\nProduto %d:\n", i + 1);
        printf("Código: ");
        scanf("%d", &estoque[i].codigo);

        printf("Nome: ");
        getchar(); // Limpa o \n do buffer
        fgets(estoque[i].nome, TAM_NOME, stdin);

        printf("Quantidade em estoque: ");
        scanf("%d", &estoque[i].quantidade);

        printf("Preço de venda: R$ ");
        scanf("%f", &estoque[i].preco);
    }

    // Procurar produto com maior preço
    int indice_maior_preco = 0;
    int indice_maior_quantidade = 0;

    for (i = 1; i < n; i++) {
        if (estoque[i].preco > estoque[indice_maior_preco].preco) {
            indice_maior_preco = i;
        }
        if (estoque[i].quantidade > estoque[indice_maior_quantidade].quantidade) {
            indice_maior_quantidade = i;
        }
    }

    printf("\nProduto com MAIOR PREÇO DE VENDA:\n");
    printf("Código: %d\n", estoque[indice_maior_preco].codigo);
    printf("Nome: %s\n", estoque[indice_maior_preco].nome);
    printf("Quantidade: %d\n", estoque[indice_maior_preco].quantidade);
    printf("Preço: R$ %.2f\n", estoque[indice_maior_preco].preco);

    printf("\nProduto com MAIOR QUANTIDADE EM ESTOQUE:\n");
    printf("Código: %d\n", estoque[indice_maior_quantidade].codigo);
    printf("Nome: %s\n", estoque[indice_maior_quantidade].nome);
    printf("Quantidade: %d\n", estoque[indice_maior_quantidade].quantidade);
    printf("Preço: R$ %.2f\n", estoque[indice_maior_quantidade].preco);

    free(estoque);
    return 0;
}
