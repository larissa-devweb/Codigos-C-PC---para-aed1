//como precisa voltar em modulo, tentei por define e no editorial havia %1_000_000_007 , entao usei como MODULO
#include <stdio.h>

#define MOD 1000000007
#define MAX 1001  // tamanho máximo do vetor de entrada

// Vetores para armazenar fatorial e inversos modulares
long long fatorial [1001];
long long inverso[1001]; 

//para fazer expoente e dividir pelo MOD(%)
long long potencia(long long base, long long expoente) {
    long long resultado = 1;
    base %= MOD;

    while (expoente > 0) {
        if (expoente % 2 == 1)
            resultado = (resultado * base) % MOD;

        base = (base * base) % MOD;
        expoente /= 2;
    }

    return resultado;
}

//pre- processar fatoriais e inversos para as combinaçoes, como dito no editorial que precisaria
void processar(){ //nome pessimo de funçao

  fatorial[0] = 1; //erro aqui , se coloco =1 da erro de inicializaçao, se tiro, reclama do tipo int [*],mas nao aceita char e nem por nada

    //for para fatorial
    for (int i=1; i< MAX; i++) {
        fatorial[i] = (fatorial[i - 1] * i) % MOD;
    }
    //for para os inversos das combinaçoes
    for (int i = 0; i < MAX; i++) {
            inverso[i] = potencia (fatorial[i], MOD - 2); // funçao de inverso modular
    }
}
//calcular a combinaçao (n,k) % MOD
long long combination(int n, int k) {
    if ( k < 0 || k > n) return 0;

    return (((fatorial[n] * inverso[k]) % MOD) * inverso[n - k]) % MOD; //nao tem mais facil? 
}

//funcao recursiva para contra quantas formas de saida pode ter a mesma BST = contra saidas
long long countExits (int *nums, int n) {
      if (n <= 2) return 1; // Casos base: 0, 1 ou 2 elementos sempre têm 1 forma

//contar quantos vao para esquerda (ser menor que a raiz)
int left[MAX]; // para esquerda
int right[MAX]; //para direita
int sizeLeft = 0;
int sizeRight = 0;

//for para precorrer vetor e classificar esquerda e direita
    for (int i = 1; i < n; i++) {
        if (nums[i] < nums[0]){
            left[sizeLeft++] = nums[i];
          }  else {
            right[sizeRight++] = nums[i];
    }
    }
//combinacao de "intercalaçao"de esquerda e direta, mantendo a ordem pedida. Acho que seria parecido com o P do editorial
long long intercalation = combination (sizeLeft + sizeRight, sizeLeft);

    // Recursao falada no editorial, para conta as formas nas subárvores = os nodos
    long long left_nodes = countExits (left, sizeLeft );
    long long right_nodes = countExits (right, sizeRight);

//somatorio total = P * nodos esquerda * nodos da direita, porem, precisa usar modulo
    return (((intercalation * left_nodes) % MOD) * right_nodes) % MOD;

}
//funcao dada pelo leetcode
int numOfWays(int* nums, int numsSize) {
    processar (); //vai calcular os fatoriais e seus inversos de combinaçao possiveis
    long long total = countExits(nums, numsSize);

    return (int)(((total - 1 + MOD)) % MOD); //subtrai 1 como dito no editorial, modulo evita negativo
}
