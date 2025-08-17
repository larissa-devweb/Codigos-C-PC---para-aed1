#include <stdio.h>
#include <stdlib.h>

// Comparador para qsort
int cmp(const void* a, const void* b) {
    int* env1 = *(int**)a;
    int* env2 = *(int**)b;

    if(env1[0] != env2[0])
        return env1[0] - env2[0]; // ordena pela largura crescente
    else
        return env2[1] - env1[1]; // se largura igual, altura decrescente
}

// Função principal
int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize) {
    if(envelopesSize == 0) return 0;

    // Ordena os envelopes
    qsort(envelopes, envelopesSize, sizeof(int*), cmp);

    // Array para a altura da LIS
    int* dp = (int*)malloc(envelopesSize * sizeof(int));
    int length = 0;

    for(int i = 0; i < envelopesSize; i++) {
        int h = envelopes[i][1];

        // busca binária para encontrar posição na LIS
        int left = 0, right = length;
        while(left < right) {
            int mid = left + (right - left)/2;
            if(dp[mid] < h)
                left = mid + 1;
            else
                right = mid;
        }

        dp[left] = h; // substitui ou adiciona
        if(left == length) length++; // aumenta o tamanho da LIS
    }

    free(dp);
    return length; // tamanho máximo de envelopes aninhados
}
