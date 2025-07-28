#include <stdio.h>   // Biblioteca padrão para entrada e saída (printf, scanf)
#include <stdlib.h>  // Para malloc (alocação dinâmica) e rand (números aleatórios)
#include <time.h>    // Para inicializar o gerador de números aleatórios com srand(time(NULL))

// Estrutura do nó da árvore
typedef struct No {
    int chave;           // Valor do nó
    int altura;          // Altura do nó (usada para calcular fator de balanceamento)
    struct No *esq, *dir; // Ponteiros para filho esquerdo e direito
} No;

// Função que retorna a altura de um nó
int altura(No *n) {
    if (n == NULL) return 0;  // Nó nulo tem altura 0
    return n->altura;        // Caso contrário, retorna a altura armazenada no nó
}

// Função auxiliar para calcular o máximo entre dois números
int max(int a, int b) {
    return (a > b) ? a : b;  // Retorna o maior entre a e b
}

// Cria um novo nó com uma chave
No* novoNo(int chave) {
    No* no = (No*)malloc(sizeof(No)); // Aloca memória para o nó
    no->chave = chave;                // Define a chave do nó
    no->esq = no->dir = NULL;         // Inicializa os filhos como NULL
    no->altura = 1;                   // Altura inicial do nó é 1 (folha)
    return no;                        // Retorna ponteiro para o novo nó
}

// Rotação simples para a direita (corrige desbalanceamento LL)
No* rotacaoDireita(No* y) {
    No* x = y->esq;       // x é o filho esquerdo do nó desbalanceado
    No* T2 = x->dir;      // T2 é a subárvore direita de x (que será reposicionada)

    x->dir = y;           // x passa a ser a nova raiz; y vira filho direito de x
    y->esq = T2;          // T2 vira filho esquerdo de y

    // Atualiza alturas
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;

    return x;             // Retorna nova raiz da subárvore
}

// Rotação simples para a esquerda (corrige desbalanceamento RR)
No* rotacaoEsquerda(No* x) {
    No* y = x->dir;       // y é o filho direito do nó desbalanceado
    No* T2 = y->esq;      // T2 é a subárvore esquerda de y (que será reposicionada)

    y->esq = x;           // y passa a ser a nova raiz; x vira filho esquerdo de y
    x->dir = T2;          // T2 vira filho direito de x

    // Atualiza alturas
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;

    return y;             // Retorna nova raiz da subárvore
}

// Calcula o fator de balanceamento de um nó
int fatorBalanceamento(No* n) {
    if (n == NULL) return 0;                      // Nó nulo tem FB = 0
    return altura(n->esq) - altura(n->dir);       // Diferença entre altura da esquerda e direita
}

// Insere um nó e realiza balanceamento
No* insere(No* raiz, int chave) {
    // 1️⃣ Inserção normal em árvore binária de busca (recursivo)
    if (raiz == NULL) return novoNo(chave);       // Caso base: chegou em folha, cria nó

    if (chave < raiz->chave)                      // Se chave menor, vai para esquerda
        raiz->esq = insere(raiz->esq, chave);
    else if (chave > raiz->chave)                 // Se maior, vai para direita
        raiz->dir = insere(raiz->dir, chave);
    else
        return raiz;                              // Chave duplicada: ignora

    // 2️⃣ Atualiza altura do nó atual
    raiz->altura = 1 + max(altura(raiz->esq), altura(raiz->dir));

    // 3️⃣ Calcula fator de balanceamento
    int fb = fatorBalanceamento(raiz);

    // 4️⃣ Corrige desbalanceamentos se necessário

    // Caso LL (inserção na subárvore esquerda-esquerda)
    if (fb > 1 && chave < raiz->esq->chave)
        return rotacaoDireita(raiz);

    // Caso RR (inserção na subárvore direita-direita)
    if (fb < -1 && chave > raiz->dir->chave)
        return rotacaoEsquerda(raiz);

    // Caso LR (inserção na subárvore esquerda-direita)
    if (fb > 1 && chave > raiz->esq->chave) {
        raiz->esq = rotacaoEsquerda(raiz->esq);   // Roda filho para esquerda
        return rotacaoDireita(raiz);              // Depois roda raiz para direita
    }

    // Caso RL (inserção na subárvore direita-esquerda)
    if (fb < -1 && chave < raiz->dir->chave) {
        raiz->dir = rotacaoDireita(raiz->dir);    // Roda filho para direita
        return rotacaoEsquerda(raiz);             // Depois roda raiz para esquerda
    }

    return raiz;  // Retorna raiz se já está balanceada
}

// Imprime os valores da árvore em ordem crescente
void inOrder(No* raiz) {
    if (raiz != NULL) {
        inOrder(raiz->esq);      // Visita subárvore esquerda
        printf("%d ", raiz->chave); // Imprime chave atual
        inOrder(raiz->dir);      // Visita subárvore direita
    }
}

// Verifica se uma árvore é AVL
int ehAVL(No* raiz) {
    if (raiz == NULL) return 1;  // Árvore vazia é AVL

    int fb = fatorBalanceamento(raiz); // Calcula fator de balanceamento
    if (fb > 1 || fb < -1)             // Se algum nó tem FB fora de [-1,1], não é AVL
        return 0;

    // Verifica recursivamente subárvore esquerda e direita
    return ehAVL(raiz->esq) && ehAVL(raiz->dir);
}

int main() {
    No* raiz = NULL;    // Inicializa árvore vazia
    int n, i, valor;

    printf("Quantos nós deseja inserir? ");
    scanf("%d", &n);    // Lê quantidade de nós a inserir

    srand(time(NULL));  // Semente para números aleatórios

    printf("Inserindo: ");
    for (i = 0; i < n; i++) {
        valor = rand() % 100;  // Gera número aleatório entre 0 e 99
        printf("%d ", valor);  // Mostra valor gerado
        raiz = insere(raiz, valor); // Insere valor na árvore
    }

    printf("\n\nÁrvore em ordem: ");
    inOrder(raiz);   // Imprime a árvore ordenada

    if (ehAVL(raiz)) // Verifica se árvore está balanceada
        printf("\nA árvore é AVL ✅\n");
    else
        printf("\nA árvore NÃO é AVL ❌\n");

    return 0;        // Fim do programa
}
