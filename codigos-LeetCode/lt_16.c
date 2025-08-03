/*16. 3Sum mais pr�ximo

Dado um array de inteiros numsde comprimento ne um inteiro target, encontre tr�s inteiros em numsde modo que a soma seja a mais pr�xima de target.
Retorna a soma dos tr�s n�meros inteiros .
Voc� pode assumir que cada entrada teria exatamente uma solu��o. */

#include <stdlib.h>
#include <limits.h>

// Fun��o de compara��o para qsort
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    // Ordena o vetor
    qsort(nums, numsSize, sizeof(int), cmp);

    // Vari�veis para armazenar a melhor soma encontrada e a menor diferen�a at� agora
    int closest = 0;
    int minDiff = INT_MAX;

    // Percorre todos os elementos
    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            int diff = abs(sum - target);

            if (diff < minDiff) {
                minDiff = diff;
                closest = sum;
            }

            if (sum < target) {
                left++;
            } else if (sum > target) {
                right--;
            } else {
                // Se achou a soma exata, retorna direto
                return target;
            }
        }
    }

    return closest;
}

