/* 98. Validar �rvore de Busca Bin�ria
Considerando a rootde uma �rvore bin�ria, determine se � uma �rvore de pesquisa bin�ria (BST) v�lida .
Um BST v�lido � definido da seguinte forma:

A esquerda subarvore de um n� cont�m apenas n�s com chaves estritamente menores que a chave do n�.
A sub�rvore direita de um n� cont�m apenas n�s com chaves estritamente maiores que a chave do n�.
As sub�rvores esquerda e direita tamb�m devem ser �rvores de busca bin�rias. */

/* O que � uma BST v�lida?

Uma �rvore bin�ria de busca (BST � Binary Search Tree) v�lida obedece a:

    Todo n� da sub�rvore esquerda deve ter valor menor que o n� atual.

    Todo n� da sub�rvore direita deve ter valor maior que o n� atual.

    E isso deve ser recursivamente verdadeiro para toda a �rvore.

   *** Estrat�gia:

Vamos usar uma fun��o auxiliar recursiva com faixa de valores v�lidos (min, max) para verificar cada n�.
Exemplo:

    A raiz pode estar entre LONG_MIN e LONG_MAX.

    Quando desce para a esquerda, o max muda para o valor do n� atual.

    Quando desce para a direita, o min muda.*/

    #include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Para LONG_MIN e LONG_MAX
#include <stdbool.h>

// Estrutura de um n� de �rvore bin�ria
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Fun��o auxiliar recursiva para validar a BST com faixas de valores permitidos
bool validate(struct TreeNode* root, long min, long max) {
    if (root == NULL) return true; // �rvore vazia � sempre v�lida

    // Se o valor do n� estiver fora da faixa permitida, n�o � uma BST v�lida
    if (root->val <= min || root->val >= max) return false;

    // Recursivamente verifica a sub�rvore esquerda (com novo max) e a direita (com novo min)
    return validate(root->left, min, root->val) &&
           validate(root->right, root->val, max);
}

// Fun��o principal pedida pelo Leetcode
bool isValidBST(struct TreeNode* root) {
    // Chama a fun��o auxiliar com os limites m�ximos poss�veis
    return validate(root, LONG_MIN, LONG_MAX);
}

