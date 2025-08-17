#include <stdio.h>


// Fun��o que retorna a posi��o de inser��o ou �ndice da ocorr�ncia
int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;                    // limite esquerdo da busca
    int right = numsSize - 1;        // limite direito da busca

    while (left <= right) {          // enquanto ainda houver elementos a verificar
        int mid = left + (right - left) / 2; // calcula o meio para evitar overflow

        if (nums[mid] == target) {   // se o elemento do meio for o alvo
            return mid;              // retorna o �ndice
        } else if (nums[mid] < target) { // se o meio for menor que o alvo
            left = mid + 1;          // procura na metade direita
        } else {                     // se o meio for maior que o alvo
            right = mid - 1;         // procura na metade esquerda
        }
    }

    // Se n�o encontrou, 'left' indica a posi��o correta de inser��o
    return left;
}

