## LT 148 - Lista de classificação

Considerando a headde uma lista encadeada, retorna a lista após classificá-la em ordem crescente.

Entrada:  cabeça = [4,2,1,3]
 Saída:  [1,2,3,4]

 Restrições:

    O número de nós na lista está no intervalo [0, 5 * 104].
    -105 <= Node.val <= 105

* Ideia geral (merge sort em lista ligada): 

Dividir a lista ao meio com o método fast-slow pointer (fast anda 2 vezes mais rápido que slow). Quando fast chega ao final, slow está no meio. Corte a lista ali. 

Recursivamente ordene cada metade.
Mescle as duas metades ordenadas como em merge sort, escolhendo o menor nó de cada lista a cada passo. 

Exemplo dado: Entrada [4,2,1,3]

Dividimos em [4,2] e [1,3].
Ordenamos recursivamente cada parte: [4,2] → [2,4]
E então mescla.

Complexidade: O(n log n)
