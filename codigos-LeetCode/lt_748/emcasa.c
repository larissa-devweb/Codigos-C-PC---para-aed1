#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Função que conta as letras da string ignorando números, espaços e maiúsculas
void countLetters(const char *str, int *count) {
    memset(count, 0, 26 * sizeof(int));

    for (int i = 0; str[i]; i++) {
        if (isalpha(str[i])) {
            count[tolower(str[i]) - 'a']++;
        }
    }
}

// Verifica se a palavra contém todas as letras necessárias
int isValidWord(const char *word, const int *licenseCount) {
    int wordCount[26] = {0};

    for (int i = 0; word[i]; i++) {
        if (isalpha(word[i])) {
            wordCount[tolower(word[i]) - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (licenseCount[i] > wordCount[i])
            return 0;
    }

    return 1;
}

// Função que o LeetCode quer
char* shortestCompletingWord(const char* licensePlate, char** words, int wordsSize) {
    int licenseCount[26];
    countLetters(licensePlate, licenseCount);

    char *result = NULL;

    for (int i = 0; i < wordsSize; i++) {
        if (isValidWord(words[i], licenseCount)) {
            if (result == NULL || strlen(words[i]) < strlen(result)) {
                result = words[i];
            }
        }
    }

    return result;
}

