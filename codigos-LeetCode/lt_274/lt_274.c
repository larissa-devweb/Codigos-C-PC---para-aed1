#include <stdlib.h> // Para qsort

/*
 Fun��o auxiliar de compara��o para ordenar em ordem decrescente.
 Par�metros:
   - a, b: ponteiros para inteiros
 Retorno:
   - Valor negativo se *b < *a (inverte ordem para decrescente)
   - Valor positivo se *b > *a
*/
int comparar_decrescente(const void* a, const void* b) {
    return (*(int*)b) - (*(int*)a);
}

/*
 Fun��o principal que calcula o h-index.
 Par�metros:
   - citations: vetor de inteiros representando as cita��es de cada artigo
   - citationsSize: tamanho do vetor citations
 Retorno:
   - Inteiro representando o h-index calculado
*/
int hIndex(int* citations, int citationsSize) {
    // Ordena o vetor de cita��es em ordem decrescente
    qsort(citations, citationsSize, sizeof(int), comparar_decrescente);

    int h = 0; // Inicializa o h-index como 0

    // Percorre o vetor ordenado
    for (int i = 0; i < citationsSize; i++) {
        /*
         Verifica se h� pelo menos (i+1) artigos com pelo menos (i+1) cita��es
         citations[i] >= i + 1 significa que este artigo tem cita��es suficientes
        */
        if (citations[i] >= i + 1) {
            h = i + 1; // Atualiza o h-index
        } else {
            break; // Se citations[i] < i+1, n�o h� mais h maior poss�vel
        }
    }

    return h; // Retorna o h-index calculado
}

