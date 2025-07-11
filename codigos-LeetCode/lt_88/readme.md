88. Mesclar matriz classificada

89. São fornecidos dois conjuntos de inteiros nums1 e nums2, classificados em ordem não decrescente e dois inteiros m e n, representando o número de elementos em nums1 e nums2respectivamente.

Mesclar nums1 e nums2em uma única matriz classificada em ordem não decrescente .

O array final ordenado não deve ser retornado pela função, mas sim armazenado dentro do array nums1. Para acomodar isso, nums1tem um comprimento de m + n, onde o primeiro melementos denotam os elementos que devem ser mesclados e o último nos elementos estão definidos para 0e deve ser ignorado. nums2tem um comprimento de n.

 

Exemplo 1:

Entrada:  nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 Saída:  [1,2,2,3,5,6]
 Explicação:  Os arrays que estamos mesclando são [1,2,3] e [2,5,6].
O resultado da fusão é [  1  ,  2  ,2,  3  ,5,6] com os elementos sublinhados vindos de nums1.
 

Exemplo 2:

Entrada:  nums1 = [1], m = 1, nums2 = [], n = 0
 Saída:  [1]
 Explicação:  Os arrays que estamos mesclando são [1] e [].
O resultado da fusão é [1].


 # LeetCode 88 – Merge Sorted Array

## Descrição
Mescla dois arrays ordenados nums1 e nums2 em nums1 in‑place, com complexidade O(m+n).

## Estratégia
- Usa três ponteiros: i (fim de nums1 válido), j (fim de nums2) e k (fim do espaço final).
- Compara de trás para frente para preencher nums1 sem sobrescrever dados.
- Evita deslocamentos repetitivos.

## Complexidade
- Tempo: O(n)
