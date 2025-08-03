/*217. Cont�m duplicado
Dado um array de inteiros nums, retornar truese algum valor aparecer pelo menos duas vezes na matriz e retornar falsese cada elemento for distinto*/

#include <stdbool.h>
#include <stdlib.h>

// Fun��o de compara��o para qsort
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool containsDuplicate(int* nums, int numsSize) {
    // Ordena o array
    qsort(nums, numsSize, sizeof(int), cmp);

    // Verifica se algum n�mero se repete com o seguinte
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            return true;
        }
    }

    return false;
}

