/*# LeetCode 88 – Merge Sorted Array

## Descrição
Mescla dois arrays ordenados nums1 e nums2 em nums1 in‑place, com complexidade O(m+n).

## Estratégia
- Usa três ponteiros: i (fim de nums1 válido), j (fim de nums2) e k (fim do espaço final).
- Compara de trás para frente para preencher nums1 sem sobrescrever dados.
- Evita deslocamentos repetitivos.

## Complexidade
- Tempo: O(m + n)
- Espaço: O(1)
*/

/*
 Mescla nums2 dentro de nums1 in-place.
 LeetCode espera essa assinatura:
*/
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1;               // Índice do último elemento válido em nums1
    int j = n - 1;               // Índice do último elemento em nums2
    int k = nums1Size - 1;       // Índice onde vamos escrever no nums1

    // Percorre nums1 e nums2 de trás para frente
    while (j >= 0) {
        // Se ainda há elementos em nums1 e nums1[i] > nums2[j]
        if (i >= 0 && nums1[i] > nums2[j]) {
            nums1[k] = nums1[i]; // Coloca nums1[i] no fim
            i--;                 // Move para o próximo elemento de nums1
        } else {
            nums1[k] = nums2[j]; // Coloca nums2[j] no fim
            j--;                 // Move para o próximo elemento de nums2
        }
        k--;                     // Move o índice de escrita para trás
    }
}
