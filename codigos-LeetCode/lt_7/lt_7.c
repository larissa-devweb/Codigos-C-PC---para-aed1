#include <limits.h> // Para usar INT_MAX e INT_MIN

/*
 Fun��o que reverte os d�gitos de um n�mero inteiro.
 Par�metro:
    - x: n�mero inteiro a ser revertido
 Retorno:
    - Inteiro com os d�gitos de x invertidos
    - 0 se o n�mero revertido ultrapassar os limites de 32 bits
*/
int reverse(int x) {
    int resultado = 0; // Vari�vel para armazenar o n�mero revertido

    while (x != 0) {
        int digito = x % 10; // Pega o �ltimo d�gito de x
        x /= 10;             // Remove o �ltimo d�gito de x

        // Verifica se resultado*10 + digito causar� overflow positivo
        if (resultado > INT_MAX / 10 || (resultado == INT_MAX / 10 && digito > 7))
            return 0;

        // Verifica se resultado*10 + digito causar� overflow negativo
        if (resultado < INT_MIN / 10 || (resultado == INT_MIN / 10 && digito < -8))
            return 0;

        resultado = resultado * 10 + digito; // Adiciona o d�gito no resultado
    }

    return resultado; // Retorna o n�mero revertido
}

