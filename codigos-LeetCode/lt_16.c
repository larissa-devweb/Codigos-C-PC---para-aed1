/*16. 3Sum mais próximo

Dado um array de inteiros numsde comprimento ne um inteiro target, encontre três inteiros em numsde modo que a soma seja a mais próxima de target.
Retorna a soma dos três números inteiros .
Você pode assumir que cada entrada teria exatamente uma solução. */

#include <stdlib.h>
#include <limits.h>

// Função de comparação para qsort
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    // Ordena o vetor
    qsort(nums, numsSize, sizeof(int), cmp);

    // Variáveis para armazenar a melhor soma encontrada e a menor diferença até agora
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

