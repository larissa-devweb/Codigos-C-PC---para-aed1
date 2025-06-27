#include <stdio.h>
#include <string.h>

#define MAX 100

// Estrutura da pilha
typedef struct {
    char dados[MAX];
    int topo;
} Pilha;

// Inicializa a pilha
void reset(Pilha *p) {
    p->topo = 0;
}

// Insere um caractere na pilha
void push(Pilha *p, char c) {
    if (p->topo < MAX) {
        p->dados[p->topo++] = c;
    }
}

// Remove um caractere do topo da pilha
char pop(Pilha *p) {
    if (p->topo > 0) {
        return p->dados[--p->topo];
    }
    return '\0';
}

// Verifica se � pal�ndromo
int ehPalindromo(char palavra[]) {
    Pilha p;
    reset(&p);

    int len = strlen(palavra);

    // Coloca todos os caracteres na pilha
    for (int i = 0; i < len; i++) {
        push(&p, palavra[i]);
    }

    // Compara os caracteres na ordem inversa
    for (int i = 0; i < len; i++) {
        if (palavra[i] != pop(&p)) {
            return 0; // N�o � pal�ndromo
        }
    }

    return 1; // � pal�ndromo
}

int main() {
    char palavra[] = "arara";

    if (ehPalindromo(palavra))
        printf("� pal�ndromo!\n");
    else
        printf("N�o � pal�ndromo.\n");

    return 0;
}
