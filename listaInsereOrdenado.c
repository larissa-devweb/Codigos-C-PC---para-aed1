//Implemente uma função que ordene os elementos que são inseridos(insereOrdenado). Após imprima a lista ordenada.
//Definir struct para representar os nós da lista encadeada.
//Cada nó deve conter um valor inteiro e um ponteiro para o próximo nó.
//Criar um nó dinamicamente e Uma função para alocar memória para um novo nó e definir seu valor.
//Inserção ordenada:
//Se a lista estiver vazia, o novo nó se torna a cabeça da lista.
//Se o novo valor for menor que o primeiro elemento, ele deve ser inserido no início.
//Caso contrário, percorrer a lista até encontrar a posição correta e inserir o nó.
//Impressão da lista. Criar uma função que percorre a lista e imprime os valores na tela.
//estar no main.
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int val;
    struct Nodo *prox;
} Nodo;

// Declaração das funções antes do main
Nodo *criarNodo(int val);
Nodo *inserirOrdenado(Nodo *inicio, int val);
void imprimirLista(Nodo *atual);
void liberarLista(Nodo *inicio);

int main(){
    Nodo *inicio = NULL;
    int val, n; //n = memoria de alocação

    printf ("Quantos numeros quer inserir?: "); //para alocaçao
    scanf ("%d", &n);

//inserir elementos
        for (int i = 0; i < n; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &val);
        inicio = inserirOrdenado(inicio, val);
    }

//imprimir
            printf("\nLista ordenada:\n");
            imprimirLista(inicio);

// Libera memoria
            liberarLista(inicio);

return 0;
}
Nodo *criarNodo(int val) {
    Nodo *novoNodo = (Nodo *)malloc(sizeof(Nodo));
    if (novoNodo == NULL) {
        printf("Erro de alocação\n");
        exit(1);
    }
    novoNodo->val = val;
    novoNodo->prox = NULL;
    return novoNodo;
}

// Inserção ordenada de um novo nó na lista
Nodo *inserirOrdenado(Nodo *inicio, int val) {
    Nodo *novoNodo = criarNodo(val);

    // Caso a lista esteja vazia ou o novo valor seja menor que o primeiro elemento
    if (inicio == NULL || inicio->val >= val) {
        novoNodo->prox = inicio;
        return novoNodo;
    }

    // Percorrer a lista para encontrar a posição correta
    Nodo *atual = inicio;
    while (atual->prox != NULL && atual->prox->val < val) {
        atual = atual->prox;
    }

    // Linhas chaves para inserir um novo nó entre dois nós existentes em uma lista encadeada.
    novoNodo->prox = atual->prox; // Conectar o novo nó ao próximo nó
    atual->prox = novoNodo; // Agora atual->prox aponta para novoNodo, ajustando a ligação

    return inicio;
}

// Função para imprimir a lista
void imprimirLista(Nodo *atual) {
    // Percorre a lista até chegar no NULL
    while (atual != NULL) {
        printf("%d -> ", atual->val);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Função para liberar a memória alocada para a lista encadeada
void liberarLista(Nodo *inicio) {
    Nodo *temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->prox;
        free(temp); // Libera cada nó individualmente
    }
}
