/*104. Maximum Depth of Binary Tree

Considerando a rootde uma árvore binária, retorna sua profundidade máxima .
de uma árvore binária A profundidade máxima é o número de nós ao longo do caminho mais longo, do nó raiz até o nó folha mais distante
** Lógica:Simples e recursiva:Se o nó é NULL, a profundidade é 0.Senão, a profundidade é 1 + máximo entre a profundidade da esquerda e da direita.*/

#include <stdio.h>
#include <stdlib.h>

// Definição do nó da árvore binária
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Função principal para calcular a profundidade máxima
int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0; // Se o nó é nulo, profundidade é 0

    // Calcula profundidade da subárvore esquerda
    int leftDepth = maxDepth(root->left);

    // Calcula profundidade da subárvore direita
    int rightDepth = maxDepth(root->right);

    // A profundidade do nó atual é 1 (ele mesmo) + maior profundidade entre os filhos
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

