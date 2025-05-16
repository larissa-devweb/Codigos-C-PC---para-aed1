#include <stdio.h>
#include <stdbool.h> // Para usar o tipo bool

// Fun��o para verificar se um n�mero � primo
bool ehPrimo(int numero) {
    // N�meros menores ou iguais a 1 n�o s�o primos
    if (numero <= 1) return false;

    // Verifica divisores de 2 at� a raiz quadrada do n�mero
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return false; // N�o � primo se for divis�vel por i
        }
    }

    return true; // Se n�o encontrou divisores, � primo
}

// Fun��o principal para testar a verifica��o de n�mero primo
int main() {
    int numero;

    // Solicita ao usu�rio que insira um n�mero
    printf("Digite um n�mero para verificar se � primo: ");
    scanf("%d", &numero); // L� o n�mero do usu�rio

    // Verifica se o n�mero � primo e imprime a mensagem apropriada
    if (ehPrimo(numero)) {
        printf("%d � um n�mero primo.\n", numero);
    } else {
        printf("%d n�o � um n�mero primo.\n", numero);
    }

    return 0; // Retorna 0 para indicar sucesso
}
