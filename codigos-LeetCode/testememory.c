#include <stdlib.h>
#include <stdio.h> // Para getchar()

int main() {
    int *vazamento = malloc(100); // Vazamento proposital
    printf("Pressione Enter para sair...");
    getchar(); // Mant�m o programa aberto
    return 0;
}
