/*106 – Construct Binary Tree from Inorder and Postorder Traversal.
Objetivo:

Dado:

    inorder[]: percurso em ordem da árvore

    postorder[]: percurso pós-ordem

Reconstruir a árvore binária original.
🧠 Ideia principal:
Características importantes:

    O último elemento do postorder é sempre a raiz da árvore (ou subárvore).

    No inorder, tudo à esquerda da raiz está na subárvore esquerda, e tudo à direita, na subárvore direita.

    A gente vai reconstruindo a árvore de trás pra frente no postorder, usando um índice global que vai diminuindo.
*/

#include <stdio.h>
#include <stdlib.h>

// Definição do nó da árvore binária
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Função para criar um novo nó
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Função para encontrar o índice de um valor no vetor inorder
int findIndex(int* inorder, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1; // Não deveria acontecer
}

// Função recursiva para construir a árvore
struct TreeNode* build(int* inorder, int* postorder, int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) return NULL; // Caso base: subárvore vazia

    // Pega o valor atual da raiz no postorder (começando do fim)
    int rootVal = postorder[*postIndex];
    (*postIndex)--; // Decrementa o índice global do postorder

    // Cria o nó da raiz
    struct TreeNode* root = newNode(rootVal);

    // Se não há filhos (folha), retorna o nó
    if (inStart == inEnd) return root;

    // Acha a posição da raiz no inorder
    int inIndex = findIndex(inorder, inStart, inEnd, rootVal);

    // IMPORTANTE: primeiro monta a subárvore direita, depois a esquerda!
    root->right = build(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left  = build(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

// Função principal pedida no Leetcode
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int postIndex = postorderSize - 1; // Começa do final do vetor postorder
    return build(inorder, postorder, 0, inorderSize - 1, &postIndex);
}

