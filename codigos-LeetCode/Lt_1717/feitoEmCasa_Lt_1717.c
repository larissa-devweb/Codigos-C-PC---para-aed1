#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função auxiliar que remove substrings "first""second" e acumula pontos
//remainder:para guardar o que sobrou da string, depois de remover tudo o que podia.
//points: quantos pontos você ganha ao remover essa substring.
// first e second sao o par de caracteres que quer remover = substring. Achei melhor tirar os dois de uma vez

int removeSubstring (char *s, char first, char second, int points, char *remainder) {

         int score = 0;
         int top = -1;
         int len = strlen(s);
    for (int i = 0; i < len; i++) {

        if (top >= 0 && remainder[top] == first && s[i] == second) {

                     top--;
                     score += points;
        } else {

               top = top + 1;
              remainder[top] = s[i]; // mesmo que remainder[++top] = s[i];

        }
    }
    remainder[top + 1] = '\0';
    return score;
}

int maximumGain(char* s, int x, int y) {

    int total = 0;
    int len = strlen(s);

        char *temp1 = (char *) malloc (len + 1); //Guarda o que sobra após remover a primeira substring
        char *temp2 = (char *) malloc (len + 1 ); // o que sobra após remover a segunda

if (x >= y) {
        total += removeSubstring(s, 'a', 'b', x, temp1);
        total += removeSubstring(temp1, 'b', 'a', y, temp2);
    } else {
        total += removeSubstring(s, 'b', 'a', y, temp1);
        total += removeSubstring(temp1, 'a', 'b', x, temp2);
    }


    free(temp1);
    free(temp2);

    return total;

}
int main() {
    char s[] = "cbaab";
    int x = 1, y = 2;
    int result = maximumGain(s, x, y);
    printf("Maximum Gain: %d\n", result);
    return 0;
}
