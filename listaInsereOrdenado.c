//Implemente uma fun��o que ordene os elementos que s�o inseridos(insereOrdenado). Ap�s imprima a lista ordenada.
//Definir struct para representar os n�s da lista encadeada.
//Cada n� deve conter um valor inteiro e um ponteiro para o pr�ximo n�.
//Criar um n� dinamicamente e Uma fun��o para alocar mem�ria para um novo n� e definir seu valor.
//Inser��o ordenada:
//Se a lista estiver vazia, o novo n� se torna a cabe�a da lista.
//Se o novo valor for menor que o primeiro elemento, ele deve ser inserido no in�cio.
//Caso contr�rio, percorrer a lista at� encontrar a posi��o correta e inserir o n�.
//Impress�o da lista. Criar uma fun��o que percorre a lista e imprime os valores na tela.
//estar no main.
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int val;
    struct Nodo *prox;
} Nodo;

// Declara��o das fun��es antes do main
Nodo *criarNodo(int val);
Nodo *inserirOrdenado(Nodo *inicio, int val);
void imprimirLista(Nodo *atual);
void liberarLista(Nodo *inicio);

int main(){
    Nodo *inicio = NULL;
    int val, n; //n = memoria de aloca��o

    printf ("Quantos numeros quer inserir?: "); //para aloca�ao
    scanf ("%d", &n);

//inserir elementos
        for (int i = 0; i < n; i++) {
        printf("Digite o %d� n�mero: ", i + 1);
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
        printf("Erro de aloca��o\n");
        exit(1);
    }
    novoNodo->val = val;
    novoNodo->prox = NULL;
    return novoNodo;
}

// Inser��o ordenada de um novo n� na lista
Nodo *inserirOrdenado(Nodo *inicio, int val) {
    Nodo *novoNodo = criarNodo(val);

    // Caso a lista esteja vazia ou o novo valor seja menor que o primeiro elemento
    if (inicio == NULL || inicio->val >= val) {
        novoNodo->prox = inicio;
        return novoNodo;
    }

    // Percorrer a lista para encontrar a posi��o correta
    Nodo *atual = inicio;
    while (atual->prox != NULL && atual->prox->val < val) {
        atual = atual->prox;
    }

    // Linhas chaves para inserir um novo n� entre dois n�s existentes em uma lista encadeada.
    novoNodo->prox = atual->prox; // Conectar o novo n� ao pr�ximo n�
    atual->prox = novoNodo; // Agora atual->prox aponta para novoNodo, ajustando a liga��o

    return inicio;
}

// Fun��o para imprimir a lista
void imprimirLista(Nodo *atual) {
    // Percorre a lista at� chegar no NULL
    while (atual != NULL) {
        printf("%d -> ", atual->val);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Fun��o para liberar a mem�ria alocada para a lista encadeada
void liberarLista(Nodo *inicio) {
    Nodo *temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->prox;
        free(temp); // Libera cada n� individualmente
    }
}
