/*1649. Criar uma matriz ordenada por meio de instruções

Dado um array de inteiros instructions, você é solicitado a criar uma matriz classificada a partir dos elementos em instructions.
 Você começa com um recipiente vazio nums. Para cada elemento da esquerda para a direita em instructions, insira-o em nums.
 O custo de cada inserção é o mínimo dos seguintes:

    O número de elementos atualmente em numsque são estritamente menores que instructions[i].
    O número de elementos atualmente em numsque são estritamente maiores que instructions[i].

Por exemplo, se inserir o elemento 3 em nums = [1,2,3,5], o custo de inserção é min(2, 1)(elementos 1 e 2são menores que 3,
elemento 5é maior que 3) e numsse tornará [1,2,3,3,5].
Retorna o custo total para inserir todos os elementos de instructions em nums. Como a resposta pode ser grande, retorne-a módulo 109 + 7*/

/*Estratégia:

Você precisa de uma estrutura que permita:

    Inserir valores dinamicamente.

    Contar rapidamente quantos são menores que um número e maiores que um número.

* Solução eficiente:

Usaremos uma Fenwick Tree (Binary Indexed Tree) ou uma Segment Tree. Como os valores de instructions[i] vão até 10⁵, isso é viável.

Vamos com Fenwick Tree (BIT) pois é mais simples.*/
#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define MAX 100005  // até o maior valor possível (10^5) + margem de segurança

int BIT[MAX];

// Função para atualizar o BIT (soma +1 na posição "index")
void update(int index) {
    while (index < MAX) {
        BIT[index] += 1;
        index += index & -index;
    }
}

// Função para consultar a soma prefixada até "index"
int query(int index) {
    int sum = 0;
    while (index > 0) {
        sum += BIT[index];
        index -= index & -index;
    }
    return sum;
}

// Função principal
int createSortedArray(int* instructions, int instructionsSize) {
    long cost = 0;

    // Limpa a BIT antes de começar (importante em múltiplos testes no Leetcode)
    for (int i = 0; i < MAX; i++) {
        BIT[i] = 0;
    }

    for (int i = 0; i < instructionsSize; i++) {
        int num = instructions[i];

        // Quantos são menores que num
        int menores = query(num - 1);

        // Quantos são maiores que num
        int maiores = i - query(num);

        // Adiciona o custo mínimo entre os dois
        cost = (cost + (menores < maiores ? menores : maiores)) % MOD;

        // Atualiza o BIT com o valor atual
        update(num);
    }

    return (int)cost;
}
