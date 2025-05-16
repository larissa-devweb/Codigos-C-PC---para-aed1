#include <stdio.h>
#include <string.h>

#define LINHA 3
#define COLUNA 4

// Regras de busca:
//Movimentos para percorrer o tabuleiro : cima, baixo, esquerda, direita
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int conferirSituacao();
int percorrerTabuleiro();

int main() {
     char tabuleiro[LINHA][COLUNA] = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    const char* palavra = "ABCCED";

    if (conferirSituacao(tabuleiro, palavra)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
//FUNÇAO para ver se a posicao é valida e nao foi usada (Não pode repetir a mesma célula durante a mesma tentativa de montar a palavra.)

int percorrerTabuleiro (int linha, int coluna,int conferido[linha][coluna] ){
if (linha >= 0 && linha < LINHA && coluna >= 0 && coluna < COLUNA && conferido[linha][coluna] == 0) {
        return 1;
    }
    return 0;
}

int conferirSituacao (char tabuleiro[LINHA][COLUNA],const char* palavra) {
    int tamanho = strlen(palavra);
    int i, j, passo, x, y;
//passo: ideia de andar peça a peça , como um joguinho

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            if (tabuleiro[i][j] == palavra[0]) {
                int conferido[LINHA][COLUNA];
                for (x = 0; x < 3; x++) {
                    for (y = 0; y < 4; y++) {
                        conferido[x][y] = 0;
                    }
                }

                int linha = i;
                int coluna = j;
                conferido[linha][coluna] = 1;

                passo = 1;
                while (passo < tamanho) {
                    char alvo = palavra[passo];
                    int achou = 0; //achou celula(peça) livre do tabuleiro

                    // cima
                    if (percorrerTabuleiro(linha - 1, coluna, conferido) &&
                        tabuleiro[linha - 1][coluna] == alvo) {
                        linha = linha - 1;
                        achou = 1;
                    }
                    // baixo
                    else if (percorrerTabuleiro(linha + 1, coluna, conferido) &&
                             tabuleiro[linha + 1][coluna] == alvo) {
                        linha = linha + 1;
                        achou = 1;
                    }
                    // esquerda
                    else if (percorrerTabuleiro(linha, coluna - 1, conferido &&
                             tabuleiro[linha][coluna - 1] == alvo)) {
                        coluna = coluna - 1;
                        achou = 1;
                    }
                    //direita
                     else if (percorrerTabuleiro(linha, coluna +1, conferido) &&
                            tabuleiro[linha][coluna + 1 ] == alvo ) {
                        coluna = coluna + 1;
                        achou = 1;
                            }
            //verificacao
                    if (achou){
                        conferido[linha][coluna] = 1; 
                        passo++;
                    } else {
                        break; //nao achou a proxima letra
                    }

                    if (passo == tamanho) {
                        return 1; //achou a palavra
                    }
                }
            }
        }
         return 0;
}
}

