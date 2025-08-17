#include <stdio.h>

// Fun��o principal
int arrangeCoins(int n) {
    long left = 0, right = n; // usamos long para evitar overflow em mid*(mid+1)/2

    while(left <= right) {
        long mid = left + (right - left) / 2;       // ponto m�dio
        long coins = mid * (mid + 1) / 2;          // soma das primeiras mid moedas

        if(coins == n) {                            // encontramos exatamente o n�mero de linhas
            return mid;
        } else if(coins < n) {                      // ainda podemos formar mais linhas
            left = mid + 1;
        } else {                                    // excedeu n, precisamos reduzir
            right = mid - 1;
        }
    }

    return right; // maior n�mero de linhas completas poss�vel
}

// Exemplo de teste
//int main() {
  //  int n = 8;
  //  printf("Linhas completas: %d\n", arrangeCoins(n)); // sa�da: 3
  //  return 0;
//}
