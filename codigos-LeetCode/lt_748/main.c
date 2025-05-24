#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Função que conta as letras da string (ignorando números, espaços e maiúsculas)
void countLetters(const char *str, int *count) {
    memset(count, 0, 26 * sizeof(int));
    for (int i = 0; str[i]; i++) {
        if (isalpha(str[i])) {
            count[tolower(str[i]) - 'a']++; 
        }
    }
}
// Verificar se palavra é válida
int isvalideWord (const char *word, int licenseCount ) {
    int i;
    int wordCount[26] = {0}; // Vetor que conta as ocorrências de cada letra
    for (i = 0; i < word[i]; i++) { //erro
        wordCount[word[i] - 'a']; // nao serve de nada: faz nada, só acessa a posição e não altera.
    }

    // Verifica se todas as letras necessárias estão presentes na palavra
    for (int i = 0; i < 26; i++) {
        if (licenseCount > wordCount[i]) // Erro: licenseCount[i]
            return 0; 
    }
    return 1; 
}

// Função principal
char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    int licenseCount[26];
    int i;
    countLetters(licensePlate, licenseCount);

    char *result = NULL;
    for(i=0; i< wordsSize;i++){
        if (isvalideWord(words[i], *licenseCount)) {
            if (result == NULL || strlen(words[i]) < strlen(result)) {
                result = words[i]; // Apenas aponta, não precisa copiar
            }
        }
    }
    return result;
}

int main (){
    char licensePlate[100];
    int wordSize;

    //char licensePlate = int isvalideWord (const char *word, int licenseCount );
    printf ("Digite palavra/plate(ex:1s3 PSt) a ser traduzida:");
    fgets (licensePlate,sizeof(licensePlate), stdin);
    licensePlate[strcspn(licensePlate, "\n")] = 0;

    printf("Digite a quantidade de palavras: ");
    scanf("%d", &wordSize);
    getchar();
//alocar espaço para as palavras
    char **words = (char **)malloc (sizeof(char *) * wordSize);
   /* if (wordSize == NULL) {
        return 1;
    }*/
    for (int i = 0; i < wordSize; i++) {

        words[i] = (char *)malloc( sizeof(char) * 100); // Cada palavra até 100 caracteres
        printf("Digite a palavra %d: ", i + 1);
        fgets (words[i], 100, stdin);
        words[i][strcspn(words[i],"\n")] = 0;
    }
    //problema com char de license plate, diz que foi te==declarado antes, mas se eu tirar, da mais erros
        char *result = shortestCompletingWord(char * licensePlate, char** words, int wordsSize);

        printf ("a menor palavra encontrada e: %s\n", result);

    //liberar memoria em for, so liberar tava dando erro...
    for (i=0; i < wordSize;i++ ) {
        free(word[i]);
    }
    free(words);

   return 0;
}
