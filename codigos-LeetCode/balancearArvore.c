// Função para balancear o lado esquerdo da árvore
int BalancaEsquerda(TNo** ppRaiz) {
    // Calcula o fator de balanceamento da subárvore esquerda
    int fbe = FB((*ppRaiz)->pEsq); // FB = altura(esq) - altura(dir)

    // Caso 1: Subárvore esquerda está desbalanceada para a esquerda (LL)
    if (fbe > 0) {
        RSD(ppRaiz); // Rotação simples à direita
        return 1;    // Balanceamento realizado
    }
    // Caso 2: Subárvore esquerda está desbalanceada para a direita (LR)
    else if (fbe < 0) {
        // Primeiro aplica uma rotação simples à esquerda no filho esquerdo
        RSE(&((*ppRaiz)->pEsq));
        // Depois aplica uma rotação simples à direita na raiz
        RSD(ppRaiz);
        return 1;    // Balanceamento realizado
    }
    // Caso 3: Não foi necessário balancear
    return 0;
}

// Função para balancear o lado direito da árvore
int BalancaDireita(TNo** ppRaiz) {
    // Calcula o fator de balanceamento da subárvore direita
    int fbd = FB((*ppRaiz)->pDir); // FB = altura(esq) - altura(dir)

    // Caso 1: Subárvore direita está desbalanceada para a direita (RR)
    if (fbd < 0) {
        RSE(ppRaiz); // Rotação simples à esquerda
        return 1;    // Balanceamento realizado
    }
    // Caso 2: Subárvore direita está desbalanceada para a esquerda (RL)
    else if (fbd > 0) {
        // Primeiro aplica uma rotação s
