#include <stdio.h>
#include <stdlib.h>

// Problema 88: merge dois arrays ordenados nums1 e nums2 em nums1 in-place

void merge(int* nums1, int m, int* nums2, int n) {

/*Define ponteiros i, j, k para processar os vetores de tr�s pra frente � isso evita sobrepor elementos ainda n�o processados.*/

    // i aponta para o fim dos elementos v�lidos em nums1
    int i = m - 1;
    // j aponta para o fim de nums2
    int j = n - 1;
    // k aponta para o fim total do espa�o em nums1 (tamanho m+n-1)
    int k = m + n - 1;

    // Enquanto ainda houver elementos em nums2 para processar...
    while (j >= 0) { //O while (j >= 0) garante que todos os elementos de nums2 ser�o colocados, mesmo que nums1 acabe antes
        // Se ainda houver elementos em nums1 e nums1[i] > nums2[j]

        if (i >= 0 && nums1[i] > nums2[j]) { //A condi��o i >= 0 && nums1[i] > nums2[j] decide qual valor colocar na posi��o atual de nums1.
            nums1[k] = nums1[i];  // coloca nums1[i] na posi��o k
            i--;
                             // move i para tr�s
        } else {
            nums1[k] = nums2[j];  // coloca nums2[j] na posi��o k
            j--;                   // move j para tr�s
        }
        k--; // decrementa k pra pr�xima posi��o
    }
}

int main() {
    // Exemplo de teste
    int nums1[10] = {1, 3, 5, 0, 0, 0}; // espa�o extra para nums2
    int nums2[3]  = {2, 4, 6};
    int m = 3, n = 3;

    merge(nums1, m, nums2, n);

    // Imprime o resultado
    for (int idx = 0; idx < m + n; idx++) {
        printf("%d ", nums1[idx]);
    }
    printf("\n");
    return 0;
}
