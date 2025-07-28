/*📖 O que está acontecendo?
 A função percorre a árvore inteira recursivamente e:
Confere se cada subárvore é AVL.
Calcula o fator de balanceamento (FB) em cada nó.
Se algum FB não estiver entre -1 e 1, a árvore não é AVL.
Só retorna 1 se todos os nós respeitarem a regra.*/

// Função que verifica se uma árvore binária é uma árvore AVL
int EhArvoreAvl(TNo* pRaiz) {
    int fb; // variável para armazenar o fator de balanceamento do nó atual

    // Caso base: se a árvore (ou subárvore) está vazia, é AVL por definição
    if (pRaiz == NULL)
        return 1; // retorna verdadeiro

    // Verifica recursivamente se a subárvore esquerda é AVL
    if (!EhArvoreAvl(pRaiz->pEsq))
        return 0; // se a esquerda não é AVL, então a árvore inteira não é

    // Verifica recursivamente se a subárvore direita é AVL
    if (!EhArvoreAvl(pRaiz->pDir))
        return 0; // se a direita não é AVL, então a árvore inteira não é

    // Calcula o fator de balanceamento do nó atual
    fb = FB(pRaiz); // FB = altura(esq) - altura(dir)

    // Verifica se o fator de balanceamento está fora do intervalo permitido [-1, 1]
    if ((fb > 1) || (fb < -1))
        return 0; // desequilibrada → não é AVL
    else
        return 1; // balanceada → é AVL
}

