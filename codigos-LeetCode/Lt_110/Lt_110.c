#include <stdbool.h> // Importa o tipo bool (true/false) usado na função principal
#include <stdlib.h>  // Importa abs(), usada para calcular valor absoluto

/*
 Função auxiliar: calcula a altura da árvore e
 verifica se a árvore está balanceada ao mesmo tempo.
 Parâmetros:
    - raiz: ponteiro para o nó atual da árvore
 Retorno:
    - Inteiro >= 0: altura da subárvore se balanceada
    - -1: indica que a subárvore não está balanceada
*/
int altura(struct TreeNode* raiz) {
    if (raiz == NULL)
        return 0; // 🌱 Caso base: se o nó for NULL, altura = 0 (árvore vazia é balanceada)

    // 🔽 Calcula altura da subárvore esquerda de forma recursiva
    int altura_esq = altura(raiz->left);
    if (altura_esq == -1)
        return -1; // ⚠️ Se a subárvore esquerda for desequilibrada, propaga -1

    // 🔽 Calcula altura da subárvore direita de forma recursiva
    int altura_dir = altura(raiz->right);
    if (altura_dir == -1)
        return -1; // ⚠️ Se a subárvore direita for desequilibrada, propaga -1

    // 📝 Verifica se a diferença de alturas entre subárvores é maior que 1
    if (abs(altura_esq - altura_dir) > 1)
        return -1; // ⚠️ Desequilíbrio detectado (diferença > 1)

    // 📏 Retorna altura da subárvore atual (altura maior + 1)
    return 1 + (altura_esq > altura_dir ? altura_esq : altura_dir);
}

/*
 Função principal: determina se a árvore binária é balanceada.
 Parâmetros:
    - root: ponteiro para o nó raiz da árvore
 Retorno:
    - true (1): se a árvore for balanceada
    - false (0): se a árvore NÃO for balanceada
*/
bool isBalanced(struct TreeNode* root) {
    // ✅ Se altura(root) retorna -1, a árvore é desequilibrada
    // ✅ Se retorna >=0, a árvore é balanceada
    return altura(root) != -1;
}
