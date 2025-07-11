#include <stdlib.h> // Para qsort

/*
 Função auxiliar de comparação para ordenar em ordem decrescente.
 Parâmetros:
   - a, b: ponteiros para inteiros
 Retorno:
   - Valor negativo se *b < *a (inverte ordem para decrescente)
   - Valor positivo se *b > *a
*/
int comparar_decrescente(const void* a, const void* b) {
    return (*(int*)b) - (*(int*)a);
}

/*
 Função principal que calcula o h-index.
 Parâmetros:
   - citations: vetor de inteiros representando as citações de cada artigo
   - citationsSize: tamanho do vetor citations
 Retorno:
   - Inteiro representando o h-index calculado
*/
int hIndex(int* citations, int citationsSize) {
    // Ordena o vetor de citações em ordem decrescente
    qsort(citations, citationsSize, sizeof(int), comparar_decrescente);

    int h = 0; // Inicializa o h-index como 0

    // Percorre o vetor ordenado
    for (int i = 0; i < citationsSize; i++) {
        /*
         Verifica se há pelo menos (i+1) artigos com pelo menos (i+1) citações
         citations[i] >= i + 1 significa que este artigo tem citações suficientes
        */
        if (citations[i] >= i + 1) {
            h = i + 1; // Atualiza o h-index
        } else {
            break; // Se citations[i] < i+1, não há mais h maior possível
        }
    }

    return h; // Retorna o h-index calculado
}

