#Simule uma pilha (LIFO) usando apenas filas (FIFO). Implemente as funções:
#push(x), pop(), top() e empty()

#Minha ideia:Ter duas filas: q1 e q2 e com push: Enfileira em q2, depois move tudo de q1 pra q2, e troca os nomes delas

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Estrutura de fila simples (FIFO)
typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
} Fila;

// Inicializa uma fila
void initFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

// Verifica se a fila está vazia
int filaVazia(Fila *f) {
    return f->inicio == f->fim;
}

// Enfileira um valor
void enqueue(Fila *f, int val) {
    if (f->fim < MAX) {
        f->dados[f->fim++] = val;
    }
}

// Desenfileira e retorna o valor
int dequeue(Fila *f) {
    if (!filaVazia(f)) {
        return f->dados[f->inicio++];
    }
    return -1; // erro
}

// Retorna o valor da frente
int front(Fila *f) {
    if (!filaVazia(f)) {
        return f->dados[f->inicio];
    }
    return -1;
}

// Estrutura que representa a pilha usando duas filas
typedef struct {
    Fila q1;  // fila principal
    Fila q2;  // fila auxiliar
} MyStack;

// Cria a pilha
MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    initFila(&stack->q1);
    initFila(&stack->q2);
    return stack;
}

// Insere um elemento na pilha
void myStackPush(MyStack* obj, int x) {
    // Passo 1: Enfileira na fila auxiliar
    enqueue(&obj->q2, x);

    // Passo 2: Move todos da fila principal pra auxiliar
    while (!filaVazia(&obj->q1)) {
        enqueue(&obj->q2, dequeue(&obj->q1));
    }

    // Passo 3: Troca q1 e q2
    Fila temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}

// Remove o topo da pilha
int myStackPop(MyStack* obj) {
    return dequeue(&obj->q1);
}

// Retorna o topo da pilha
int myStackTop(MyStack* obj) {
    return front(&obj->q1);
}

// Verifica se está vazia
int myStackEmpty(MyStack* obj) {
    return filaVazia(&obj->q1);
}

// Libera memória
void myStackFree(MyStack* obj) {
    free(obj);
}

// Teste simples
int main() {
    MyStack* pilha = myStackCreate();

    myStackPush(pilha, 10);
    myStackPush(pilha, 20);
    myStackPush(pilha, 30);

    printf("Topo: %d\n", myStackTop(pilha));  // Deve imprimir 30
    printf("Pop: %d\n", myStackPop(pilha));   // Remove 30
    printf("Topo: %d\n", myStackTop(pilha));  // Deve imprimir 20

    myStackFree(pilha);
    return 0;
}





