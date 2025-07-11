Dado um conjunto de inteiros citations onde citations[i]é o número de citações que um pesquisador recebeu por seu ithartigo,
retorne o índice h do pesquisador .
De acordo com a definição de índice h na Wikipedia : O índice h é definido como o valor máximo de hde modo que o 
pesquisador em questão tenha publicado pelo menos hartigos que foram citados pelo menos uma vez hvezes.
* Exemplo 1:

Entrada:  citações = [3,0,6,1,5]
 Saída:  3
 Explicação:  [3,0,6,1,5] significa que o pesquisador tem 5 artigos no total e cada um deles recebeu 3, 0, 6, 1, 5 citações, respectivamente.
Como o pesquisador tem 3 artigos com pelo menos 3 citações cada e os dois restantes com no máximo 3 citações cada, seu índice h é 3.

* Exemplo 2:

Entrada:  citações = [1,3,1]
 Saída:  1
 ]Restrições:

    n == citations.length
    1 <= n <= 5000
    0 <= citations[i] <= 1000

## Explicação do algoritmo

* Ordenamos as citações em ordem decrescente para facilitar a contagem.
* Percorremos o vetor:
- Em cada posição i, verificamos se existem (i+1) artigos com pelo menos (i+1) citações.

  Complexidade:
  Tempo: O(n log n), dominado pela ordenação com qsort.
  Espaço: O(1), exceto o espaço usado por qsort.
  
## Estratégia
1. Ordena o vetor de citações em ordem decrescente.
2. Para cada posição `i` no vetor:
   - Verifica se existem `i+1` artigos com pelo menos `i+1` citações.
3. Retorna o maior valor `h` encontrado.

  

    Quando essa condição falha, o h-index já está definido.
