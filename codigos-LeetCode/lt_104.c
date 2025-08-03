/*104. Maximum Depth of Binary Tree

Considerando a rootde uma �rvore bin�ria, retorna sua profundidade m�xima .
de uma �rvore bin�ria A profundidade m�xima � o n�mero de n�s ao longo do caminho mais longo, do n� raiz at� o n� folha mais distante
** L�gica:Simples e recursiva:Se o n� � NULL, a profundidade � 0.Sen�o, a profundidade � 1 + m�ximo entre a profundidade da esquerda e da direita.*/

#include <stdio.h>
#include <stdlib.h>

// Defini��o do n� da �rvore bin�ria
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Fun��o principal para calcular a profundidade m�xima
int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0; // Se o n� � nulo, profundidade � 0

    // Calcula profundidade da sub�rvore esquerda
    int leftDepth = maxDepth(root->left);

    // Calcula profundidade da sub�rvore direita
    int rightDepth = maxDepth(root->right);

    // A profundidade do n� atual � 1 (ele mesmo) + maior profundidade entre os filhos
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

