#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para o dado armazenado na fila
typedef struct {
    char nome[50];
} Cliente;

// Estrutura do nó da fila
typedef struct Nodo {
    Cliente cliente;
    struct Nodo *prox;
} Nodo;

// Estrutura da fila
typedef struct {
    Nodo *inicio;
    Nodo *fim;
} Fila;

// Função para criar fila
void inicializar(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

// Verifica se a fila está vazia
int vazia(Fila *fila) {
    return fila->inicio == NULL;
}

// Insere cliente no fim da fila
void push(Fila *fila, Cliente c) {
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    novo->cliente = c;
    novo->prox = NULL;

    if (vazia(fila)) {
        fila->inicio = novo;
    } else {
        fila->fim->prox = novo;
    }
    fila->fim = novo;
}

// Remove cliente do início da fila
int pop(Fila *fila, Cliente *c) {
    if (vazia(fila)) return 0;

    Nodo *temp = fila->inicio;
    *c = temp->cliente;

    fila->inicio = temp->prox;
    if (fila->inicio == NULL)
        fila->fim = NULL;

    free(temp);
    return 1;
}

// Exibe todos os clientes na fila
void exibirFila(Fila *fila) {
    Nodo *atual = fila->inicio;
    while (atual != NULL) {
        printf("Cliente: %s\n", atual->cliente.nome);
        atual = atual->prox;
    }
}

// Programa principal
int main() {
    Fila fila;
    Cliente c;

    inicializar(&fila);

    Cliente c1 = {"Maria"};
    Cliente c2 = {"João"};
    Cliente c3 = {"Larissa"};

    push(&fila, c1);
    push(&fila, c2);
    push(&fila, c3);

    printf("Fila atual:\n");
    exibirFila(&fila);

    printf("\nAtendendo um cliente...\n");
    pop(&fila, &c);
    printf("Atendido: %s\n", c.nome);

    printf("\nFila após atendimento:\n");
    exibirFila(&fila);

    return 0;
}
