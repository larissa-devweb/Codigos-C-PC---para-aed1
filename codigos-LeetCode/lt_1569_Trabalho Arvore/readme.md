 LeetCode 1569 - Number of Ways to Reorder Array to Get Same BST

## Enunciado:

Dado um array de inteiros distintos, quantas maneiras diferentes você pode reordená-lo para que,
ao inserir os elementos numa BST na ordem dada, a árvore final seja a mesma da original.

Input: [2,1,3]
Output: 1

## Lógica

- O primeiro elemento define a raiz da BST.
- Os outros são divididos entre esquerda (menores) e direita (maiores).
- As formas de reordenar preservando a BST: usa ideia do editorial

## ideias

- Programacão Modular: usando módulo 
- Combinações: pré-processando fatorial e inverso
- Divisão e conquista (recursão) para subarvores
- Subtrai 1 no final pois a ordem original nao consta: ideia do editorial

* Precisa do inverso pois mexe com modulo e pela matematica Dividir por b é o mesmo que multiplicar pelo inverso modular de b, ou seja: a / b mod M = a * inv(b) mod M.
