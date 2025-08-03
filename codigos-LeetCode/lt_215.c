/*215. K-�simo maior elemento em uma matriz
Dado um array de inteiros numse um inteiro k, retorne o kth maior elemento da matriz .
Note que � o kthmaior elemento na ordem classificada, n�o o kthelemento distinto.
Voc� consegue resolver sem classificar? */

#include <stdlib.h>

// Fun��o de compara��o decrescente para qsort
int cmp(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);  // Ordem decrescente
}

int findKthLargest(int* nums, int numsSize, int k) {
    // Ordena o vetor em ordem decrescente
    qsort(nums, numsSize, sizeof(int), cmp);

    // Retorna o k-�simo maior (�ndice k - 1)
    return nums[k - 1];
}

