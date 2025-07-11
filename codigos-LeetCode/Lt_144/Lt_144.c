//Binary Tree Preorder Traversal
/*#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da árvore binária
typedef struct TreeNode {
    int val;                 // Valor armazenado no nó
    struct TreeNode *left;   // Ponteiro para o filho esquerdo
    struct TreeNode *right;  // Ponteiro para o filho direito
} TreeNode;

/*
 Função recursiva para fazer a travessia pré-ordem da árvore.
 Ordem: Raiz -> Esquerda -> Direita

void preorder(TreeNode* root) {
    if (root == NULL) return;           // Caso base: árvore vazia

    printf("%d ", root->val);           // 1️⃣ Imprime valor do nó atual (raiz)
    preorder(root->left);               // 2️⃣ Visita subárvore esquerda
    preorder(root->right);              // 3️⃣ Visita subárvore direita
}*/

#include <stdlib.h>

/*
    Função auxiliar para percorrer a árvore em pré-ordem (raiz -> esquerda -> direita)
    e armazenar os valores em um vetor.

    Parâmetros:
        - root: ponteiro para o nó atual
        - resultado: vetor onde os valores serão armazenados
        - indice: ponteiro para o índice atual no vetor resultado
*/
void percorrer(struct TreeNode* root, int* resultado, int* indice) {
    if (root == NULL) return; // Caso base: árvore vazia, nada a fazer

    resultado[*indice] = root->val; // Armazena valor do nó atual
    (*indice)++;                    // Avança índice para próxima posição

    percorrer(root->left, resultado, indice);  // Visita subárvore esquerda
    percorrer(root->right, resultado, indice); // Visita subárvore direita
}

/*
    Função principal: retorna um vetor com os valores da árvore em pré-ordem.

    Parâmetros:
        - root: ponteiro para o nó raiz da árvore
        - returnSize: ponteiro para inteiro onde será armazenado o tamanho do vetor retornado

    Retorno:
        - Ponteiro para o vetor dinâmico com os valores em pré-ordem
*/
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    // Aloca memória para armazenar os valores da árvore
    // (tamanho máximo possível: 100 elementos)
    int* resultado = (int*)malloc(100 * sizeof(int));

    int indice = 0; // Índice inicial no vetor resultado
    percorrer(root, resultado, &indice); // Preenche o vetor com os valores da árvore

    *returnSize = indice; // Define o tamanho real do vetor preenchido
    return resultado;     // Retorna o vetor com os valores
}
