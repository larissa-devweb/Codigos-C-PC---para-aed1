/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



// Função para calcular a altura da árvore pela esquerda
int leftHeight(struct TreeNode* node) {
    int h = 0;
    while (node) {
        h++;
        node = node->left; // percorre sempre a esquerda
    }
    return h;
}

// Função para calcular a altura da árvore pela direita
int rightHeight(struct TreeNode* node) {
    int h = 0;
    while (node) {
        h++;
        node = node->right; // percorre sempre a direita
    }
    return h;
}

// Função principal para contar nós
int countNodes(struct TreeNode* root) {
    if (!root) return 0; // árvore vazia

    int lh = leftHeight(root);   // altura à esquerda
    int rh = rightHeight(root);  // altura à direita

    if (lh == rh) {
        // árvore perfeita, podemos usar a fórmula 2^h - 1
        return (1 << lh) - 1; // shift para calcular 2^lh
    } else {
        // árvore não perfeita, contamos recursivamente
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

