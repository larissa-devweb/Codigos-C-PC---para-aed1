/* 98. Validar Árvore de Busca Binária
Considerando a rootde uma árvore binária, determine se é uma árvore de pesquisa binária (BST) válida .
Um BST válido é definido da seguinte forma:

A esquerda subarvore de um nó contém apenas nós com chaves estritamente menores que a chave do nó.
A subárvore direita de um nó contém apenas nós com chaves estritamente maiores que a chave do nó.
As subárvores esquerda e direita também devem ser árvores de busca binárias. */

/* O que é uma BST válida?

Uma árvore binária de busca (BST – Binary Search Tree) válida obedece a:

    Todo nó da subárvore esquerda deve ter valor menor que o nó atual.

    Todo nó da subárvore direita deve ter valor maior que o nó atual.

    E isso deve ser recursivamente verdadeiro para toda a árvore.

   *** Estratégia:

Vamos usar uma função auxiliar recursiva com faixa de valores válidos (min, max) para verificar cada nó.
Exemplo:

    A raiz pode estar entre LONG_MIN e LONG_MAX.

    Quando desce para a esquerda, o max muda para o valor do nó atual.

    Quando desce para a direita, o min muda.*/

    #include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Para LONG_MIN e LONG_MAX
#include <stdbool.h>

// Estrutura de um nó de árvore binária
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Função auxiliar recursiva para validar a BST com faixas de valores permitidos
bool validate(struct TreeNode* root, long min, long max) {
    if (root == NULL) return true; // Árvore vazia é sempre válida

    // Se o valor do nó estiver fora da faixa permitida, não é uma BST válida
    if (root->val <= min || root->val >= max) return false;

    // Recursivamente verifica a subárvore esquerda (com novo max) e a direita (com novo min)
    return validate(root->left, min, root->val) &&
           validate(root->right, root->val, max);
}

// Função principal pedida pelo Leetcode
bool isValidBST(struct TreeNode* root) {
    // Chama a função auxiliar com os limites máximos possíveis
    return validate(root, LONG_MIN, LONG_MAX);
}

