#include <stdio.h>    // Biblioteca padr�o de I/O
#include <stdlib.h>   // Para malloc e free

// Estrutura de um n� da �rvore
typedef struct No {
    int valor;               // Valor armazenado no n�
    struct No* esquerda;     // Ponteiro para o filho da esquerda
    struct No* direita;      // Ponteiro para o filho da direita
} No;

// Fun��o que cria um novo n� com valor dado
No* novoNo(int valor) {
    No* no = (No*) malloc(sizeof(No));  // Aloca mem�ria para um novo n�
    no->valor = valor;                  // Define o valor
    no->esquerda = NULL;                // Inicializa os filhos como NULL
    no->direita = NULL;
    return no;                          // Retorna o ponteiro para o novo n�
}

// Fun��o para inserir um valor na �rvore
No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        // Se a �rvore estiver vazia, cria novo n� como raiz
        return novoNo(valor);
    }

    if (valor < raiz->valor) {
        // Se o valor for menor, insere na sub�rvore esquerda
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }
    else if (valor > raiz->valor) {
        // Se o valor for maior, insere na sub�rvore direita
        raiz->direita = inserir(raiz->direita, valor);
    }
    // Se o valor j� existir, n�o faz nada (sem duplicatas)
    return raiz;  // Retorna a raiz original (ou atualizada)
}

// Fun��o para buscar um valor na �rvore
int buscar(No* raiz, int valor) {
    if (raiz == NULL) {
        // Se chegou em NULL, n�o encontrou
        return 0;
    }

    if (valor == raiz->valor) {
        // Achou o valor
        return 1;
    } else if (valor < raiz->valor) {
        // Busca na esquerda se for menor
        return buscar(raiz->esquerda, valor);
    } else {
        // Busca na direita se for maior
        return buscar(raiz->direita, valor);
    }
}

// Percurso em ordem (esquerda, raiz, direita) � imprime em ordem crescente
void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);       // Visita a esquerda
        printf("%d ", raiz->valor);    // Imprime o valor do n�
        emOrdem(raiz->direita);        // Visita a direita
    }
}
int main() {
    No* raiz = NULL;  // Come�a com �rvore vazia

    // Insere alguns valores
    raiz = inserir(raiz, 8);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 1);
    raiz = inserir(raiz, 6);

    printf("�rvore em ordem: ");
    emOrdem(raiz);  // Deve imprimir: 1 3 6 8 10
    printf("\n");

    // Busca por um valor
    int x = 6;
    if (buscar(raiz, x)) {
        printf("%d foi encontrado!\n", x);
    } else {
        printf("%d n�o est� na �rvore.\n", x);
    }

    return 0;
}

