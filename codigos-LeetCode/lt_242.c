#include <stdbool.h>
#include <string.h>

bool isAnagram(char* s, char* t) {
    if(strlen(s) != strlen(t)) return false; // anagramas precisam ter o mesmo tamanho

    int count[26] = {0}; // contagem para cada letra de 'a' a 'z'

    for(int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++; // incrementa letra de s
        count[t[i] - 'a']--; // decrementa letra de t
    }

    // se todas posições forem 0, são anagramas
    for(int i = 0; i < 26; i++) {
        if(count[i] != 0) return false;
    }

    return true;
}
