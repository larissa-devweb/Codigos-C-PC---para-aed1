// Fun��o para balancear o lado esquerdo da �rvore
int BalancaEsquerda(TNo** ppRaiz) {
    // Calcula o fator de balanceamento da sub�rvore esquerda
    int fbe = FB((*ppRaiz)->pEsq); // FB = altura(esq) - altura(dir)

    // Caso 1: Sub�rvore esquerda est� desbalanceada para a esquerda (LL)
    if (fbe > 0) {
        RSD(ppRaiz); // Rota��o simples � direita
        return 1;    // Balanceamento realizado
    }
    // Caso 2: Sub�rvore esquerda est� desbalanceada para a direita (LR)
    else if (fbe < 0) {
        // Primeiro aplica uma rota��o simples � esquerda no filho esquerdo
        RSE(&((*ppRaiz)->pEsq));
        // Depois aplica uma rota��o simples � direita na raiz
        RSD(ppRaiz);
        return 1;    // Balanceamento realizado
    }
    // Caso 3: N�o foi necess�rio balancear
    return 0;
}

// Fun��o para balancear o lado direito da �rvore
int BalancaDireita(TNo** ppRaiz) {
    // Calcula o fator de balanceamento da sub�rvore direita
    int fbd = FB((*ppRaiz)->pDir); // FB = altura(esq) - altura(dir)

    // Caso 1: Sub�rvore direita est� desbalanceada para a direita (RR)
    if (fbd < 0) {
        RSE(ppRaiz); // Rota��o simples � esquerda
        return 1;    // Balanceamento realizado
    }
    // Caso 2: Sub�rvore direita est� desbalanceada para a esquerda (RL)
    else if (fbd > 0) {
        // Primeiro aplica uma rota��o s
