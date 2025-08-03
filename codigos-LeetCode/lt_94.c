/*Leetcode 94 � Binary Tree Inorder Traversal pede que a gente retorne o percurso em ordem (inorder) de
uma �rvore bin�ria. Ou seja, visitar a sub�rvore esquerda, depois o n� atual, e por fim a sub�rvore direita.
Como o tamanho da �rvore � desconhecido no in�cio, usamos aloca��o din�mica para o vetor de resposta,
e passamos um ponteiro returnSize para indicar quantos elementos o vetor final tem.*/
#include <stdio.h>
#include <stdlib.h>

// Estrutura padr�o de n� da �rvore bin�ria usada no Leetcode
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Fun��o auxiliar recursiva para percorrer a �rvore em ordem e preencher o vetor
void inorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) return; // Se o n� for nulo, nada a fazer

    inorder(root->left, result, index);     // Visita a sub�rvore esquerda

    result[*index] = root->val;             // Adiciona o valor do n� atual no vetor
    (*index)++;                             // Incrementa o �ndice para o pr�ximo valor

    inorder(root->right, result, index);    // Visita a sub�rvore direita
}

// Fun��o principal pedida pelo Leetcode
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    // Alocamos espa�o suficiente para at� 100 elementos (ajust�vel)
    int* result = (int*)malloc(sizeof(int) * 100);
    int index = 0; // �ndice atual do vetor (quantos elementos j� inserimos)

    inorder(root, result, &index); // Chama a fun��o recursiva para preencher o vetor

    *returnSize = index; // Atualiza o tamanho real da resposta
    return result;       // Retorna o vetor com os elementos em ordem
}
