/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
    Função que ordena uma lista ligada usando o algoritmo de insertion sort.
    Parâmetro:
        - head: ponteiro para o primeiro nó da lista ligada
    Retorno:
        - ponteiro para o primeiro nó da lista ordenada
*/
struct ListNode* insertionSortList(struct ListNode* head) {
    // Caso base: lista vazia ou com apenas 1 elemento já está ordenada
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Cria um nó dummy que servirá como "cabeça" da lista ordenada
    struct ListNode dummy;
    dummy.next = NULL; // Inicialmente a lista ordenada está vazia

    // Ponteiro para percorrer a lista original
    struct ListNode* atual = head;

    // Percorre cada nó da lista original
    while (atual != NULL) {
        // Guarda o próximo nó antes de mexer no ponteiro next
        struct ListNode* proximo = atual->next;

        // Encontra a posição correta na lista ordenada para inserir o nó atual
        struct ListNode* prev = &dummy;
        while (prev->next != NULL && prev->next->val < atual->val) {
            prev = prev->next; // Avança até achar o lugar certo
        }

        // Insere o nó atual entre prev e prev->next
        atual->next = prev->next; // O próximo do atual passa a ser o próximo do prev
        prev->next = atual;       // prev agora aponta para o atual

        // Move para o próximo nó da lista original
        atual = proximo;
    }

    // Retorna o início da lista ordenada (dummy.next aponta para o primeiro nó ordenado)
    return dummy.next;
}

