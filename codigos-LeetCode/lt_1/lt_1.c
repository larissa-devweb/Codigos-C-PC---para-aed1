#include <stdlib.h>

/*
 Função para resolver o problema Two Sum:
   - Encontra dois índices i e j no array tal que nums[i] + nums[j] == target.
   - Retorna um vetor com os índices encontrados.

 Parâmetros:
   - nums: vetor de inteiros
   - numsSize: tamanho do vetor nums
   - target: valor alvo a ser somado
   - returnSize: ponteiro para armazenar o tamanho do vetor retornado (sempre 2)

 Retorno:
   - Ponteiro para vetor com os dois índices (alocado dinamicamente)
*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Aloca espaço para o vetor resultado (sempre de tamanho 2)
    int* resultado = (int*)malloc(2 * sizeof(int));

    // Percorre o vetor nums com dois loops (força bruta)
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) { // Se encontrar a soma igual ao target
                resultado[0] = i; // Guarda o índice i
                resultado[1] = j; // Guarda o índice j
                *returnSize = 2;  // O vetor resultado sempre tem tamanho 2
                return resultado; // Retorna o vetor de índices
            }
        }
    }

    // Caso não encontre (não esperado no problema), retorna NULL
    *returnSize = 0;
    return NULL;
}
