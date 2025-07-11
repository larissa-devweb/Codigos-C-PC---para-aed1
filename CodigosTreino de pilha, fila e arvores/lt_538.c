#include <stdlib.h>

/*
 Estrutura TreeNode já fornecida pelo LeetCode:

 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };
*/

// Variável global para manter a soma acumulada
int soma_acumulada = 0;

/*
 Função auxiliar que faz a travessia reversa da árvore (direita -> raiz -> esquerda)
 Atualiza o valor de cada nó para ser a soma de todos os valores maiores ou iguais a ele.

 Parâmetro:
   - root: ponteiro para o nó atual da árvore
*/
void converter(struct TreeNode* root) {
    if (root == NULL) return; // Caso base: nó vazio

    // 1️⃣ Visita a subárvore direita primeiro (nós com valores maiores)
    converter(root->right);

    // 2️⃣ Atualiza a soma acumulada com o valor do nó atual
    soma_acumulada += root->val;

    // 3️⃣ Atualiza o valor do nó com a soma acumulada
    root->val = soma_acumulada;

    // 4️⃣ Visita a subárvore esquerda (nós com valores menores)
    converter(root->left);
}

/*
 Função principal chamada pelo LeetCode
 Converte a BST em uma Greater Tree conforme a regra acima

 Parâmetro:
   - root: ponteiro para a raiz da árvore

 Retorno:
   - ponteiro para a raiz da árvore modificada
*/
struct TreeNode* convertBST(struct TreeNode* root) {
    soma_acumulada = 0;  // Reseta a soma acumulada antes de começar
    converter(root);     // Executa a conversão
    return root;         // Retorna a raiz modificada
}
