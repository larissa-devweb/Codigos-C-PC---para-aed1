147. Lista de classificação de inserção
Considerando a headde uma lista encadeada simples, classifique a lista usando a classificação por inserção e
 retorne o cabeçalho da lista classificada .

As etapas do algoritmo de ordenação por inserção :

    A classificação por inserção itera, consumindo um elemento de entrada a cada repetição e aumentando uma lista de saída classificada.
    A cada iteração, a classificação por inserção remove um elemento dos dados de entrada, encontra o local ao qual 
    ele pertence na lista classificada e o insere lá.
    Ele se repete até que não haja mais elementos de entrada.

A seguir, um exemplo gráfico do algoritmo de ordenação por inserção. A lista parcialmente ordenada (preta) 
contém inicialmente apenas o primeiro elemento da lista.
Um elemento (vermelho) é removido dos dados de entrada e inserido no lugar na lista ordenada a cada iteração. 

## Descrição
Ordena uma lista ligada usando o algoritmo insertion sort.

## Estratégia
- Cria uma lista ordenada auxiliar com um nó dummy no início.
- Para cada nó da lista original:
  - Encontra a posição correta na lista ordenada.
  - Insere o nó na posição.
- No final, todos os nós estão em ordem crescente.

## Complexidade
- Tempo: O(n²)
- Espaço: O(1) (usa apenas ponteiros auxiliares)


COMPLEXIDADE: 
Tempo: O(n²) no pior caso (se a lista original estiver em ordem inversa)
