#Implemente uma fila simples que gerencia senhas de atendimento.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Estrutura da fila
typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
} Fila;

void reset(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

int vazia(Fila *f) {
    return f->inicio == f->fim;
}

int cheia(Fila *f) {
    return f->fim == MAX;
}

void push(Fila *f, int valor) {
    if (!cheia(f)) {
        f->dados[f->fim++] = valor;
    } else {
        printf("Fila cheia!\n");
    }
}

int pop(Fila *f) {
    if (!vazia(f)) {
        return f->dados[f->inicio++];
    } else {
        printf("Fila vazia!\n");
        return -1;
    }
}

int main() {
    Fila f;
    reset(&f);

    // Simulando senhas
    push(&f, 101);
    push(&f, 102);
    push(&f, 103);

    printf("Chamando senha: %d\n", pop(&f));
    printf("Chamando senha: %d\n", pop(&f));

    return 0;
}
