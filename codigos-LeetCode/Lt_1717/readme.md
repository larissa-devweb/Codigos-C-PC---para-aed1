## LeetCode 1717 : Maximum Score From Removing Substrings

 Enunciado:

 Dada uma string s e dois inteiros x e y, você pode remover quantas vezes quiser as substrings "ab" (ganhando x pontos) e "ba" (ganhando y pontos). O objetivo é maximizar a pontuação total após todas as remoções possíveis.

Exemplo:
        - Entrada: s = "cdbcbbaaabab", x = 4, y = 5
        - saida = 19

Como fiz? 

- Simulação de pilha com array
- remover primeiro a substring que vale mais pontos
- para saber fim da pilha, usei  remainder[top + 1] = '\0';

Resultados:
- Todos os 77 casos de teste passaram
- Uso de memória: ~8MB (alocação de dois buffers auxiliares temporários)
- Complexidade: O(n)






//comentarios:


  remainder[++top] = s[i];

  resumo: 

Essa linha faz duas coisas ao mesmo tempo:
    -Avança o ponteiro da pilha (como se você dissesse "quero empilhar mais um")
    -Coloca o novo caractere no topo da pilha
