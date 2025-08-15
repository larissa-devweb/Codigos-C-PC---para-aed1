// Função para mesclar duas listas ordenadas em uma só (padrão do merge)
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) {
    // Cria um nó temporário só para facilitar o início da lista final
    struct ListNode temp;
    struct ListNode* tail = &temp; // Ponteiro para o fim da nova lista

    temp.next = NULL; // Começa a lista vazia

    // Enquanto houver elementos nas duas listas
    while (l1 && l2) {
        if (l1->val < l2->val) { // Se o valor de l1 for menor
            tail->next = l1;     // adiciona l1 na nova lista
            l1 = l1->next;       // avança l1
        } else {
            tail->next = l2;     // senão, adiciona l2
            l2 = l2->next;       // avança l2
        }
        tail = tail->next; // anda com o ponteiro da nova lista
    }

    // Se ainda sobrou algo em uma das listas, adiciona no fim
    if (l1) tail->next = l1;
    if (l2) tail->next = l2;

    return temp.next; // Retorna a cabeça da nova lista ordenada
}

// Função principal: ordena a lista com Merge Sort
struct ListNode* sortList(struct ListNode* head) {
    // Caso base: se a lista estiver vazia ou tiver só um nó, já está ordenada
    if (!head || !head->next) return head;

    // Ponteiros para dividir a lista em duas partes
    struct ListNode* slow = head;         // Anda 1 em 1
    struct ListNode* fast = head->next;   // Anda 2 em 2

    // Aqui achamos o meio da lista
    //Quando fast chega ao final, slow está no meio e ai será cortado ali.
    while (fast && fast->next) {
        slow = slow->next;           // move 1 passo
        fast = fast->next->next;     // move 2 passos
    }

    // Agora o slow está no meio da lista
    struct ListNode* mid = slow->next; // meio/mid = (início da segunda metade)
    slow->next = NULL;                 // corta a lista no meio 

    // Recursivamente ordena as duas metades 
    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(mid);

    // Mescla as duas listas ja ordenadas
    return merge(left, right);
}
