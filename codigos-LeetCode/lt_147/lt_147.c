/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
    Fun��o que ordena uma lista ligada usando o algoritmo de insertion sort.
    Par�metro:
        - head: ponteiro para o primeiro n� da lista ligada
    Retorno:
        - ponteiro para o primeiro n� da lista ordenada
*/
struct ListNode* insertionSortList(struct ListNode* head) {
    // Caso base: lista vazia ou com apenas 1 elemento j� est� ordenada
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Cria um n� dummy que servir� como "cabe�a" da lista ordenada
    struct ListNode dummy;
    dummy.next = NULL; // Inicialmente a lista ordenada est� vazia

    // Ponteiro para percorrer a lista original
    struct ListNode* atual = head;

    // Percorre cada n� da lista original
    while (atual != NULL) {
        // Guarda o pr�ximo n� antes de mexer no ponteiro next
        struct ListNode* proximo = atual->next;

        // Encontra a posi��o correta na lista ordenada para inserir o n� atual
        struct ListNode* prev = &dummy;
        while (prev->next != NULL && prev->next->val < atual->val) {
            prev = prev->next; // Avan�a at� achar o lugar certo
        }

        // Insere o n� atual entre prev e prev->next
        atual->next = prev->next; // O pr�ximo do atual passa a ser o pr�ximo do prev
        prev->next = atual;       // prev agora aponta para o atual

        // Move para o pr�ximo n� da lista original
        atual = proximo;
    }

    // Retorna o in�cio da lista ordenada (dummy.next aponta para o primeiro n� ordenado)
    return dummy.next;
}

