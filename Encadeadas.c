#include <stdio.h>
#include <stdlib.h>

// Defini��o da estrutura do n�
typedef struct Nodo {
    int val;
    struct Nodo *prox;
} Nodo;

// Criar um novo n� com um pr�ximo definido
Nodo* criar(int val, Nodo *prox) {
    Nodo *novoNodo = (Nodo*) malloc(sizeof(Nodo));
    if (novoNodo == NULL) {
        printf("Erro de aloca��o\n");
        exit(1);
    }
    novoNodo->val = val;
    novoNodo->prox = prox;
    return novoNodo;
}

// Fun��o para inserir elementos ordenadamente na lista
Nodo* insereOrdenado(Nodo *inicio, int val) {
    Nodo *novo = criar(val, NULL);
    if (inicio == NULL || inicio->val >= val) {
        novo->prox = inicio;
        return novo;
    }
    Nodo *atual = inicio;
    while (atual->prox != NULL && atual->prox->val < val) {
        atual = atual->prox;
    }
    novo->prox = atual->prox;
    atual->prox = novo;
    return inicio;
}

// Fun��o para inverter a lista
Nodo* inverterLista(Nodo *inicio) {
    Nodo *anterior = NULL, *atual = inicio, *prox = NULL;
    while (atual != NULL) {
        prox = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = prox;
    }
    return anterior;
}

// Fun��o para remover elementos duplicados
void removerDuplicados(Nodo *inicio) {
    Nodo *atual = inicio;
    while (atual != NULL && atual->prox != NULL) {
        if (atual->val == atual->prox->val) {
            Nodo *temp = atual->prox;
            atual->prox = atual->prox->prox;
            free(temp);
        } else {
            atual = atual->prox;
        }
    }
}

// Fun��o para imprimir a lista
void imprimirLista(Nodo *atual) {
    while (atual != NULL) {
        printf("%d -> ", atual->val);
        atual = atual->prox;
    }
    printf("NULL\n");
}

int main() {
    Nodo *inicio = NULL;

    // Inser��o ordenada
    inicio = insereOrdenado(inicio, 30);
    inicio = insereOrdenado(inicio, 10);
    inicio = insereOrdenado(inicio, 20);
    inicio = insereOrdenado(inicio, 40);
    inicio = insereOrdenado(inicio, 20);
    printf("Lista ordenada:\n");
    imprimirLista(inicio);

    // Invers�o da lista
    inicio = inverterLista(inicio);
    printf("Lista invertida:\n");
    imprimirLista(inicio);

    // Removendo duplicatas
    removerDuplicados(inicio);
    printf("Lista sem duplicatas:\n");
    imprimirLista(inicio);

    return 0;
}
