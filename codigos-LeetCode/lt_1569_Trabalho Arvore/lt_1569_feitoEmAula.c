//como precisa voltar em modulo, tentei por define e no editorial havia %1_000_000_007 , entao usei como MODULO
#include <stdio.h>

#define MOD 1000000007
#define MAX 1001  // tamanho m�ximo do vetor de entrada

// Vetores para armazenar fatorial e inversos modulares
int fatorial [MAX];
int inverso[MAX];

//para fazer expoente e dividir pelo MOD(%), vai garantir que resultado englobe par, impar, primo
//levando em conta que módulo primo (10⁹ + 7) 
int potencia (int base, int expoente) {

    int resultado =1;
    base %= MOD;

    while(expoente > 0) {
        if (expoente % 2 == 1) {
            resultado = (resultado * base) % MOD;
        } else {
            base = (base * base) %MOD;
             expoente /= 2;
        }
    }
            return resultado;
}
//pre- processar fatoriais e inversos para as combina�oes, como dito no editorial que precisaria
// Calcula todos os fatoriais de 0 até MAX - 1 com módulo (% MOD), guardando em fatorial[].
// pq? Evita calcular fatorial toda vez que precisar da combinação.
void processar(){ //nome pessimo de fun�ao

  int fatorial[0] = 1; //erro aqui , se coloco =1 da erro de inicializa�ao, se tiro, reclama do tipo int [*]

    //for para fatorial
    for (int i=1; i< MAX; i++) {
        fatorial[i] = (fatorial[i - 1] * i) % MOD;
    }
    //for para os inversos das combina�oes
    for (int i = 0; i < MAX; i++) {
//Para cada fatorial, calcula seu inverso modular usando a função potencia() com expoente MOD - 2
//Guarda os resultados em inverso[]

    inverso[i] = potencia (fatorial[i], MOD - 2); // envolvendo primo,por isso -2
}
}
//// Calcula C(n, k) usando a fórmula modular: C(n, k) = n! / (k! * (n-k)!) mod MOD
int combination(int n, int k) {
    if ( k < 0 || k > n) return 0; // para caso neg e maior que n, retorna 0

//fatorial[n] = n!
// inverso[k] = k!)⋅inv(k!)≡1modMOD, isso faz a parte da combinaçao que divide por k!
//Como nao pode dividir, multiplica pelo inverso[n - k] = é o mesmo , so que é parte da divisao do n-k!
    return (((fatorial[n] * inverso[k]) % MOD) * inverso[n - k]) % MOD; 
}

//funcao recursiva para contra quantas formas de saida pode ter a mesma BST = contra saidas
 int countExits (int *nums, int n) {
      if (n <= 2) return 1; // Casos base: 0, 1 ou 2 elementos sempre tem 1 

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
//combinacao de "intercala�ao"de esquerda e direta, mantendo a ordem pedida. 
//Acho que seria parecido com o P do editorial e O P representa o número de formas de intercalar 
//as sequências da subárvore esquerda e da direita, mantendo a ordem relativa de cada uma

int intercalation = combination (sizeLeft + sizeRight, sizeLeft);

//sizeLeft + sizeRight: total de filhos do nó raiz.
//sizeLeft: quantos elementos vão para a subárvore esquerda.

    // Recursao falada no editorial, para conta as formas nas sub�rvores = os nodos
    int left_nodes = countExits (left, sizeLeft );
    int right_nodes = countExits (right, sizeRight);

//somatorio total = P * nodos esquerda * nodos da direita, porem, precisa usar modulo
    return ((intercalation *left_nodes * right_nodes)) % MOD;
}

//funcao dada pelo leetcode:
int numOfWays(int* nums, int numsSize) {
    processar(); // Pré-calcula fatoriais e inversos modulares para combinações rápidas

    int total = countExits(nums, numsSize); // Conta quantas permutações geram a mesma BST

    // Subtrai 1 porque não queremos contar a sequência original
    // O +MOD evita resultado negativo antes do módulo
    // O operador % MOD garante que o resultado fique dentro do intervalo válido (0 a MOD-1)
    return ((total - 1 + MOD)) % MOD;
}
// A função numOfWays é a interface para o usuário, que chama processar e countExits
//  Ela retorna o número de maneiras de permutar a sequência nums para manter a mesma BST,
