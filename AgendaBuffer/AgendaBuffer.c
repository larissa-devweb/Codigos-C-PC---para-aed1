#include <stdio.h>   
#include <stdlib.h>   
#include <string.h>  

int main() {
    // Aloca um buffer inicial na memória para guardar:

    void *pBuffer = malloc(
        4 +          // espaço para int total pessoas
        4 +          // espaço para int opção do menu
        sizeof(void *) * 4 +   // 4 ponteiros auxiliares (void**)
        50               // espaço para nomeBusca (string 50 bytes)
    );
    if (!pBuffer) return 1;   // Se malloc falhar, sai do programa com erro 1

    // Define ponteiros para posições específicas dentro do buffer alocado
    void **pAux1  = (void **)((char *)pBuffer + 4 + 4); // começa depois dos 2 ints
    void **pAux2  = (void **)((char *)pAux1 + sizeof(void *)); // 1 ponteiro à frente
    void **pAtual = (void **)((char *)pAux2 + sizeof(void *)); // próximo ponteiro
    void **pFim   = (void **)((char *)pAtual + sizeof(void *)); // último ponteiro auxiliar
    void *nomeBusca = (void *)((char *)pFim + sizeof(void *)); // espaço para nomeBusca

    // Inicializa total de pessoas = 0 no início do buffer
    *(int *)pBuffer = 0;                    // total pessoas começa em 0
    *(int *)((char *)pBuffer + 4) = 0;     // opção menu começa em 0
    *pFim = (char *)nomeBusca + 50;        // pFim aponta para o fim da área de registros (inicialmente só nomeBusca)

    while (1) {
        // Exibe o menu e lê a opção escolhida pelo usuário (armazenando no local reservado)
        printf("\n1-Adicionar\n2-Remover\n3-Buscar\n4-Listar\n5-Sair\nOpção: ");
        scanf("%d", (int *)((char *)pBuffer + 4)); // lê opção e salva na posição do menu no buffer
        getchar(); 

        if (*(int *)((char *)pBuffer + 4) == 1) { // Se opção for 1 (Adicionar)
            // Realoca buffer para adicionar um novo registro (104 bytes por registro)
            pBuffer = realloc(pBuffer, (char *)(*pFim) - (char *)pBuffer + 104);

            // Atualiza todos os ponteiros após o realloc (posição pode mudar)
            pAux1  = (void **)((char *)pBuffer + 4 + 4);
            pAux2  = (void **)((char *)pAux1 + sizeof(void *));
            pAtual = (void **)((char *)pAux2 + sizeof(void *));
            pFim   = (void **)((char *)pAtual + sizeof(void *));
            nomeBusca = (void *)((char *)pFim + sizeof(void *));

            *pAux1 = *pFim; // pAux1 aponta para o início do novo registro

            // Lê o nome do usuário, salva em *pAux1 (50 chars)
            printf("Nome: ");
            fgets((char *)(*pAux1), 50, stdin);
            ((char *)(*pAux1))[strcspn((char *)(*pAux1), "\n")] = 0; // remove '\n' do final

            // Lê idade do usuário, salva logo após o nome (int após 50 bytes)
            printf("Idade: ");
            scanf("%d", (int *)((char *)(*pAux1) + 50));
            getchar(); // limpa '\n' do buffer stdin

            // Lê email, salva após nome + idade (50 + 4 bytes)
            printf("Email: ");
            fgets((char *)((char *)(*pAux1) + 50 + 4), 50, stdin);
            ((char *)((char *)(*pAux1) + 50 + 4))[strcspn((char *)((char *)(*pAux1) + 50 + 4), "\n")] = 0; // remove '\n'

            // Atualiza pFim para próxima posição livre e incrementa total pessoas
            *pFim = (char *)(*pFim) + 104; // avança 104 bytes para próximo registro
            (*(int *)pBuffer)++;            // incrementa total pessoas no início do buffer
        }

        else if (*(int *)((char *)pBuffer + 4) == 2) { // Se opção for 2 (Remover)
            printf("Nome a remover: ");
            fgets((char *)nomeBusca, 50, stdin);
            ((char *)nomeBusca)[strcspn((char *)nomeBusca, "\n")] = 0; // remove '\n'

            // Ponteiro para o começo dos registros (logo após nomeBusca)
            char *pRegistros = (char *)nomeBusca + 50;
            char *pFimChar = (char *)(*pFim);

            // Percorre todos os registros procurando nome igual a nomeBusca
            while (pRegistros < pFimChar) {
                if (strcmp(pRegistros, (char *)nomeBusca) == 0) {
                    // Se achou, move os registros posteriores para apagar o atual
                    void *prox = pRegistros + 104;
                    memmove(pRegistros, prox, (char *)pFimChar - (char *)prox);
                    *pFim = (char *)(*pFim) - 104; // diminui fim do buffer
                    (*(int *)pBuffer)--;          // decrementa total pessoas
                    break;                       // sai do loop depois de remover
                }
                pRegistros += 104; // vai para próximo registro
            }
            // Ajusta o tamanho do buffer após remoção
            pBuffer = realloc(pBuffer, (char *)(*pFim) - (char *)pBuffer);

            // Atualiza ponteiros após realloc
            pAux1  = (void **)((char *)pBuffer + 4 + 4);
            pAux2  = (void **)((char *)pAux1 + sizeof(void *));
            pAtual = (void **)((char *)pAux2 + sizeof(void *));
            pFim   = (void **)((char *)pAtual + sizeof(void *));
            nomeBusca = (void *)((char *)pFim + sizeof(void *));
        }

        else if (*(int *)((char *)pBuffer + 4) == 3) { // Se opção for 3 (Buscar)
            printf("Nome a buscar: ");
            fgets((char *)nomeBusca, 50, stdin);
            ((char *)nomeBusca)[strcspn((char *)nomeBusca, "\n")] = 0; // remove '\n'

            char *pRegistros = (char *)nomeBusca + 50; // início registros
            char *pFimChar = (char *)(*pFim);

            // Percorre os registros procurando pelo nome
            while (pRegistros < pFimChar) {
                if (strcmp(pRegistros, (char *)nomeBusca) == 0) {
                    // Se achou, imprime nome, idade e email
                    printf("Nome: %s\n", pRegistros);
                    printf("Idade: %d\n", *(int *)(pRegistros + 50));
                    printf("Email: %s\n", pRegistros + 50 + 4);
                    break;
                }
                pRegistros += 104; // próximo registro
            }
        }

        else if (*(int *)((char *)pBuffer + 4) == 4) { // Se opção for 4 (Listar)
            char *pRegistros = (char *)nomeBusca + 50; // início registros
            char *pFimChar = (char *)(*pFim);

            // Percorre todos os registros, imprimindo dados
            while (pRegistros < pFimChar) {
                printf("Nome: %s | ", pRegistros);
                printf("Idade: %d | ", *(int *)(pRegistros + 50));
                printf("Email: %s\n", pRegistros + 50 + 4);
                pRegistros += 104; // próximo registro
            }
        }

        else if (*(int *)((char *)pBuffer + 4) == 5) { // Se opção for 5 (Sair)
            free(pBuffer); // libera memória alocada
            break;        // sai do loop infinito e termina programa
        }
    }

    return 0; // fim do programa, código de saída 0 (sucesso)
}
