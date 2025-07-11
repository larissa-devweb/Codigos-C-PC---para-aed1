#include <limits.h> // Para usar INT_MAX e INT_MIN

/*
 Função que reverte os dígitos de um número inteiro.
 Parâmetro:
    - x: número inteiro a ser revertido
 Retorno:
    - Inteiro com os dígitos de x invertidos
    - 0 se o número revertido ultrapassar os limites de 32 bits
*/
int reverse(int x) {
    int resultado = 0; // Variável para armazenar o número revertido

    while (x != 0) {
        int digito = x % 10; // Pega o último dígito de x
        x /= 10;             // Remove o último dígito de x

        // Verifica se resultado*10 + digito causará overflow positivo
        if (resultado > INT_MAX / 10 || (resultado == INT_MAX / 10 && digito > 7))
            return 0;

        // Verifica se resultado*10 + digito causará overflow negativo
        if (resultado < INT_MIN / 10 || (resultado == INT_MIN / 10 && digito < -8))
            return 0;

        resultado = resultado * 10 + digito; // Adiciona o dígito no resultado
    }

    return resultado; // Retorna o número revertido
}

