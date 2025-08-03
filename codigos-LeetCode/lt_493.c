/*493. Pares Reversos

Dado um array de inteiros nums, retorna o número de pares reversos na matriz .
Um par reverso é um par (i, j) onde:

    0 <= i < j < nums.length e
    nums[i] > 2 * nums[j]

 Solução eficiente: Merge Sort Modificado

A ideia é contar os pares enquanto fazemos o merge sort, aproveitando o fato de que as metades estão ordenadas.
💡 Passos:

    Divide o array em duas metades.

    Conta os pares reversos entre a metade esquerda e direita (antes de fazer o merge!).

    Faz o merge normal das duas metades.

    Soma todos os pares encontrados.

    */

    #include <stdio.h>
#include <stdlib.h>

// Função auxiliar para fazer merge sort e contar pares reversos
int mergeSort(int* nums, int* temp, int left, int right) {
    if (left >= right) return 0; // Caso base: vetor com 1 ou 0 elemento

    int mid = left + (right - left) / 2;
    int count = 0;

    // Conta recursivamente nos lados esquerdo e direito
    count += mergeSort(nums, temp, left, mid);
    count += mergeSort(nums, temp, mid + 1, right);

    // Conta os pares reversos entre os dois lados
    int j = mid + 1;
    for (int i = left; i <= mid; i++) {
        while (j <= right && (long)nums[i] > 2L * nums[j]) {
            j++;
        }
        count += (j - (mid + 1));
    }

    // Merge das duas metades ordenadas
    int i = left;
    j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }

    while (i <= mid) temp[k++] = nums[i++];
    while (j <= right) temp[k++] = nums[j++];

    // Copia o resultado de volta para o vetor original
    for (i = left; i <= right; i++) {
        nums[i] = temp[i];
    }

    return count;
}

// Função principal exigida pelo Leetcode
int reversePairs(int* nums, int numsSize) {
    if (numsSize <= 1) return 0;

    int* temp = (int*)malloc(sizeof(int) * numsSize); // Vetor auxiliar para merge
    int result = mergeSort(nums, temp, 0, numsSize - 1);
    free(temp);
    return result;
}


