// Função para inserir um novo nó na árvore AVL
int Insere(TNo** ppRaiz, Registro* x) {
    // Caso base: encontrou o local onde deve inserir o novo nó
    if (*ppRaiz == NULL) {
        *ppRaiz = (TNo*)malloc(sizeof(TNo)); // Aloca memória para o novo nó
        (*ppRaiz)->Reg = *x;                 // Copia o registro para o nó
        (*ppRaiz)->pEsq = NULL;              // Inicializa filho esquerdo como NULL
        (*ppRaiz)->pDir = NULL;              // Inicializa filho direito como NULL
        return 1;                            // Inserção realizada
    }
    // Caso 1: A chave do novo registro é menor → vai para a subárvore esquerda
    else if ((*ppRaiz)->Reg.chave > x->chave) {
        if (Insere(&((*ppRaiz)->pEsq), x)) {    // Recursão para o filho esquerdo
            if (Balanceamento(ppRaiz))         // Balanceia se necessário
                return 0;                      // Altura não mudou
            else
                return 1;                      // Altura mudou
        }
    }
    // Caso 2: A chave do novo registro é maior → vai para a subárvore direita
    else if ((*ppRaiz)->Reg.chave < x->chave) {
        if (Insere(&((*ppRaiz)->pDir), x)) {    // Recursão para o filho direito
            if (Balanceamento(ppRaiz))         // Balanceia se necessário
                return 0;                      // Altura não mudou
            else
                return 1;                      // Altura mudou
        }
    }
    // Caso 3: A chave já existe na árvore
    else
        return 0; // Não insere duplicatas

    return 0; // Valor já presente ou erro
}
