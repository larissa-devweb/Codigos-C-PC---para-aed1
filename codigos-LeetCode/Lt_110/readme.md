Passo a passo

    Se a árvore for vazia, é balanceada.

    Use uma função height(node) que retorna -1 se a subárvore não for balanceada; senão, sua altura.

    Em cada nó, chama recursivamente height(left) e height(right).

    Se qualquer um for -1, ou a diferença for >1, devolve -1.

    Senão, devolve 1 + max(esquerda, direita).

    A função principal é height(root) != -1.
