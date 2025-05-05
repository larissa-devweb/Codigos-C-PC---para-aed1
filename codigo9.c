/*
2. Considere um cadastro de produtos de um estoque, com as seguintes informa��es:
(a) Defina uma estrutura, denominada produto, com:
    - C�digo de identifica��o (int)
    - Nome do produto (at� 50 caracteres)
    - Quantidade dispon�vel no estoque (int)
    - Pre�o de venda (float)

(b) Crie um conjunto de N produtos (N � fornecido pelo usu�rio)
    - Pe�a ao usu�rio para digitar as informa��es de cada produto

(c) Encontre o produto com o maior pre�o de venda

(d) Encontre o produto com a maior quantidade dispon�vel no estoque
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
        printf("Erro ao alocar mem�ria.\n");
        return 1;
    }

    // Leitura dos produtos
    for (i = 0; i < n; i++) {
        printf("\nProduto %d:\n", i + 1);
        printf("C�digo: ");
        scanf("%d", &estoque[i].codigo);

        printf("Nome: ");
        getchar(); // Limpa o \n do buffer
        fgets(estoque[i].nome, TAM_NOME, stdin);

        printf("Quantidade em estoque: ");
        scanf("%d", &estoque[i].quantidade);

        printf("Pre�o de venda: R$ ");
        scanf("%f", &estoque[i].preco);
    }

    // Procurar produto com maior pre�o
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

    printf("\nProduto com MAIOR PRE�O DE VENDA:\n");
    printf("C�digo: %d\n", estoque[indice_maior_preco].codigo);
    printf("Nome: %s\n", estoque[indice_maior_preco].nome);
    printf("Quantidade: %d\n", estoque[indice_maior_preco].quantidade);
    printf("Pre�o: R$ %.2f\n", estoque[indice_maior_preco].preco);

    printf("\nProduto com MAIOR QUANTIDADE EM ESTOQUE:\n");
    printf("C�digo: %d\n", estoque[indice_maior_quantidade].codigo);
    printf("Nome: %s\n", estoque[indice_maior_quantidade].nome);
    printf("Quantidade: %d\n", estoque[indice_maior_quantidade].quantidade);
    printf("Pre�o: R$ %.2f\n", estoque[indice_maior_quantidade].preco);

    free(estoque);
    return 0;
}
