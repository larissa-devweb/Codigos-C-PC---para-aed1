#Implemente uma fila que armazena nomes de pessoas em ordem de chegada.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct {
    char nomes[MAX][50];
    int inicio;
    int fim;
} Fila;

void reset(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

int cheia(Fila *f) {
    return f->fim == MAX;
}

int vazia(Fila *f) {
    return f->inicio == f->fim;
}

void push(Fila *f, char nome[]) {
    if (!cheia(f)) {
        strcpy(f->nomes[f->fim++], nome);
    } else {
        printf("Fila cheia!\n");
    }
}

void pop(Fila *f) {
    if (!vazia(f)) {
        printf("Saindo da fila: %s\n", f->nomes[f->inicio++]);
    } else {
        printf("Fila vazia!\n");
    }
}

void imprimir(Fila *f) {
    printf("Fila atual:\n");
    for (int i = f->inicio; i < f->fim; i++) {
        printf("- %s\n", f->nomes[i]);
    }
}

int main() {
    Fila fila;
    reset(&fila);

    push(&fila, "Ana");
    push(&fila, "Beto");
    push(&fila, "Clara");

    imprimir(&fila);

    pop(&fila);
    imprimir(&fila);

    return 0;
}

