/*215. K-ésimo maior elemento em uma matriz
Dado um array de inteiros numse um inteiro k, retorne o kth maior elemento da matriz .
Note que é o kthmaior elemento na ordem classificada, não o kthelemento distinto.
Você consegue resolver sem classificar? */

#include <stdlib.h>

// Função de comparação decrescente para qsort
int cmp(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);  // Ordem decrescente
}

int findKthLargest(int* nums, int numsSize, int k) {
    // Ordena o vetor em ordem decrescente
    qsort(nums, numsSize, sizeof(int), cmp);

    // Retorna o k-ésimo maior (índice k - 1)
    return nums[k - 1];
}

