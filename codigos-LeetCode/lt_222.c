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



// Fun��o para calcular a altura da �rvore pela esquerda
int leftHeight(struct TreeNode* node) {
    int h = 0;
    while (node) {
        h++;
        node = node->left; // percorre sempre a esquerda
    }
    return h;
}

// Fun��o para calcular a altura da �rvore pela direita
int rightHeight(struct TreeNode* node) {
    int h = 0;
    while (node) {
        h++;
        node = node->right; // percorre sempre a direita
    }
    return h;
}

// Fun��o principal para contar n�s
int countNodes(struct TreeNode* root) {
    if (!root) return 0; // �rvore vazia

    int lh = leftHeight(root);   // altura � esquerda
    int rh = rightHeight(root);  // altura � direita

    if (lh == rh) {
        // �rvore perfeita, podemos usar a f�rmula 2^h - 1
        return (1 << lh) - 1; // shift para calcular 2^lh
    } else {
        // �rvore n�o perfeita, contamos recursivamente
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

