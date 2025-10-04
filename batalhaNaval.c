#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    // Inicializar o tabuleiro com água (0)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posicionar navio horizontal (linha 2, colunas 3 a 5)
    for (j = 3; j < 6; j++) {
        tabuleiro[2][j] = 3;
    }

    // Posicionar navio vertical (coluna 7, linhas 5 a 7)
    for (i = 5; i < 8; i++) {
        tabuleiro[i][7] = 3;
    }

    // Exibir o tabuleiro
    printf("Tabuleiro de Batalha Naval (0 = agua, 3 = navio):\n\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}