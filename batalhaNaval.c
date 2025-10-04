#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    // Inicializar tabuleiro com 0 (água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Navio horizontal (linha 0, colunas 0 a 2)
    for (j = 0; j < 3; j++) {
        tabuleiro[0][j] = 3;
    }

    // Navio vertical (coluna 5, linhas 2 a 4)
    for (i = 2; i < 5; i++) {
        tabuleiro[i][5] = 3;
    }

    // Navio diagonal principal (posição [6][0] até [8][2])
    for (i = 0; i < 3; i++) {
        tabuleiro[6 + i][0 + i] = 3;
    }

    // Navio diagonal secundária (posição [9][9] até [7][7])
    for (i = 0; i < 3; i++) {
        tabuleiro[9 - i][9 - i] = 3;
    }

    // Exibir tabuleiro
    printf("Tabuleiro de Batalha Naval (0 = agua, 3 = navio):\n\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}