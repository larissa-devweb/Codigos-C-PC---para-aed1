/*47. Permutações IIDado um conjunto de números, nums, que podem conter duplicatas, retornam todas as permutações únicas possíveis em qualquer ordem */

#include <stdlib.h>
#include <stdbool.h>

// Função de comparação para qsort
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Backtracking
void backtrack(int* nums, int numsSize, int* used, int* path, int depth,
               int** result, int* returnSize, int** returnColumnSizes) {

    // Caso base: caminho completo
    if (depth == numsSize) {
        int* perm = malloc(sizeof(int) * numsSize);
        for (int i = 0; i < numsSize; i++) {
            perm[i] = path[i];
        }
        result[*returnSize] = perm;
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }

    // Exploração de permutações
    for (int i = 0; i < numsSize; i++) {
        // Ignorar elementos já usados
        if (used[i]) continue;

        // Pular duplicatas (poda importante!)
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

        used[i] = 1;
        path[depth] = nums[i];

        backtrack(nums, numsSize, used, path, depth + 1, result, returnSize, returnColumnSizes);

        used[i] = 0; // backtrack
    }
}

// Função principal
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // Ordenar para facilitar poda de duplicatas
    qsort(nums, numsSize, sizeof(int), cmp);

    // Estimar tamanho máximo de saída (numsSize! no pior caso)
    int maxSize = 1;
    for (int i = 2; i <= numsSize; i++) maxSize *= i;

    int** result = malloc(sizeof(int*) * maxSize);
    *returnColumnSizes = malloc(sizeof(int) * maxSize);
    int* path = malloc(sizeof(int) * numsSize);
    int* used = calloc(numsSize, sizeof(int)); // inicializado com 0

    *returnSize = 0;

    backtrack(nums, numsSize, used, path, 0, result, returnSize, returnColumnSizes);

    // Libera os auxiliares
    free(path);
    free(used);

    return result;
}

