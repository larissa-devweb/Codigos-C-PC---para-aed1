/*Leetcode 94 – Binary Tree Inorder Traversal pede que a gente retorne o percurso em ordem (inorder) de
uma árvore binária. Ou seja, visitar a subárvore esquerda, depois o nó atual, e por fim a subárvore direita.
Como o tamanho da árvore é desconhecido no início, usamos alocação dinâmica para o vetor de resposta,
e passamos um ponteiro returnSize para indicar quantos elementos o vetor final tem.*/
#include <stdio.h>
#include <stdlib.h>

// Estrutura padrão de nó da árvore binária usada no Leetcode
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Função auxiliar recursiva para percorrer a árvore em ordem e preencher o vetor
void inorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return; // Se o nó for nulo, nada a fazer

    inorder(root->left, result, index);     // Visita a subárvore esquerda

    result[*index] = root->val;             // Adiciona o valor do nó atual no vetor
    (*index)++;                             // Incrementa o índice para o próximo valor

    inorder(root->right, result, index);    // Visita a subárvore direita
}

// Função principal pedida pelo Leetcode
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    // Alocamos espaço suficiente para até 100 elementos (ajustável)
    int* result = (int*)malloc(sizeof(int) * 100);
    int index = 0; // Índice atual do vetor (quantos elementos já inserimos)

    inorder(root, result, &index); // Chama a função recursiva para preencher o vetor

    *returnSize = index; // Atualiza o tamanho real da resposta
    return result;       // Retorna o vetor com os elementos em ordem
}
