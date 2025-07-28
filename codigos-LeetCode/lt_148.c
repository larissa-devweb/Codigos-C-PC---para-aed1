/* LT 148: Lista de classifica��o em ordem crescente
Como � uma lista encadeada, Merge Sort � ideal. Diferente do Quick Sort, ele:
N�o precisa de acesso aleat�rio (�ndices), pois divide pelo meio com ponteiros.
Funciona bem com listas encadeadas.
� est�vel e mant�m O(n log n).

Usaremos o Merge Sort:
 * Se a lista for vazia ou com 1 elemento, j� est� ordenada.
Sen�o:

        Dividimos a lista no meio (com ponteiros);
        Chamamos recursivamente o sortList para ordenar cada metade;
        Juntamos as duas metades com merge.

 Fun��es auxiliares que vamos usar:

    getMiddle: encontra o meio da lista;

    merge: junta duas listas ordenadas.

STRUCT DADA:
struct ListNode {
    int val;
    struct ListNode *next;
};

PONTEIROS:
slow = head;      // anda de 1 em 1
fast = head->next // anda de 2 em 2

*/
// Defini��o do n� da lista
struct ListNode {
    int val;               // Valor armazenado no n�
    struct ListNode *next; // Ponteiro para o pr�ximo n�
};

// Fun��o para mesclar duas listas ordenadas em uma s� (padr�o do merge)
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) {
    // Cria um n� tempor�rio s� para facilitar o in�cio da lista final
    struct ListNode dummy;
    struct ListNode* tail = &dummy; // Ponteiro para o fim da nova lista

    dummy.next = NULL; // Come�a a lista vazia

    // Enquanto houver elementos nas duas listas
    while (l1 && l2) {
        if (l1->val < l2->val) { // Se o valor de l1 for menor
            tail->next = l1;     // adiciona l1 na nova lista
            l1 = l1->next;       // avan�a l1
        } else {
            tail->next = l2;     // sen�o, adiciona l2
            l2 = l2->next;       // avan�a l2
        }
        tail = tail->next; // anda com o ponteiro da nova lista
    }

    // Se ainda sobrou algo em uma das listas, adiciona no fim
    if (l1) tail->next = l1;
    if (l2) tail->next = l2;

    return dummy.next; // Retorna a cabe�a da nova lista ordenada
}

// Fun��o principal: ordena a lista com Merge Sort
struct ListNode* sortList(struct ListNode* head) {
    // Caso base: se a lista estiver vazia ou tiver s� um n�, j� est� ordenada
    if (!head || !head->next) return head;

    // Ponteiros para dividir a lista em duas partes
    struct ListNode* slow = head;         // Anda 1 em 1
    struct ListNode* fast = head->next;   // Anda 2 em 2

    // Aqui achamos o meio da lista
    while (fast && fast->next) {
        slow = slow->next;           // move 1 passo
        fast = fast->next->next;     // move 2 passos
    }

    // Agora o slow est� no meio da lista
    struct ListNode* mid = slow->next; // meio verdadeiro (in�cio da segunda metade)
    slow->next = NULL;                 // corta a lista no meio

    // Recursivamente ordena as duas metades
    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(mid);

    // Mescla as duas listas ordenadas
    return merge(left, right);
}
