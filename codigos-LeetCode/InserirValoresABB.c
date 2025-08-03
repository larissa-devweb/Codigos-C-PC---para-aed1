#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// Cria um novo nó
No* novoNo(int valor) {
    No* no = (No*) malloc(sizeof(No));
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

// Insere valor na árvore
No* inserir(No* raiz, int valor) {
    if (raiz == NULL)
        return novoNo(valor);

    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserir(raiz->direita, valor);

    return raiz;
}

// Mostra árvore em ordem (menor pro maior)
void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        emOrdem(raiz->direita);
    }
}

int main() {
    No* raiz = NULL;
    int valor;

    printf("Digite os valores para inserir na árvore (digite -1 para parar):\n");

    while (1) {
        printf("Valor: ");
        scanf("%d", &valor);

        if (valor == -1)
            break;

        raiz = inserir(raiz, valor);
    }

    printf("\nValores em ordem crescente:\n");
    emOrdem(raiz);
    printf("\n");

    return 0;
}
