#include <stdio.h>

#define N 10
#define AGUA 0
#define NAVIO 3
#define HABIL 5


int dentro(int r, int c) { return (r >= 0 && r < N && c >= 0 && c < N); }

void print_tab(const int t[N][N], const char *titulo) {
    printf("\n=== %s ===\n", titulo);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
}


void marca(int t[N][N], int r, int c, int valor) {
    if (dentro(r, c) && t[r][c] != NAVIO) t[r][c] = valor;
}



void habilidade_cone(int t[N][N], int origemR, int origemC, int raio) {
    for (int k = 0; k <= raio; k++) {
        int r = origemR + k;              // desce k linhas
        int cIni = origemC - k;
        int cFim = origemC + k;
        for (int c = cIni; c <= cFim; c++) {
            marca(t, r, c, HABIL);
        }
    }
}


void habilidade_cruz(int t[N][N], int origemR, int origemC, int raio) {
    for (int k = 0; k <= raio; k++) {
        marca(t, origemR + k, origemC, HABIL);
        marca(t, origemR - k, origemC, HABIL);
        marca(t, origemR, origemC + k, HABIL);
        marca(t, origemR, origemC - k, HABIL);
    }
}


void habilidade_octaedro(int t[N][N], int origemR, int origemC, int raio) {
    for (int dr = -raio; dr <= raio; dr++) {
        int r = origemR + dr;
        int alcance = raio - (dr < 0 ? -dr : dr);  // raio - |dr|
        for (int dc = -alcance; dc <= alcance; dc++) {
            int c = origemC + dc;
            marca(t, r, c, HABIL);
        }
    }
}


void coloca_navios(int t[N][N]) {
    // horizontal
    t[1][1] = t[1][2] = t[1][3] = NAVIO;
    t[6][5] = t[6][6] = t[6][7] = NAVIO;

    // diagonal principal
    t[3][3] = t[4][4] = t[5][5] = NAVIO;

    // diagonal secundária
    t[8][2] = t[7][3] = t[6][4] = NAVIO;
}

int main(void) {
    int tab[N][N];

    // 1) inicializa água
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            tab[i][j] = AGUA;

    
    coloca_navios(tab);
    print_tab(tab, "Tabuleiro inicial (0 = agua, 3 = navio)");

    // 3) habilidades
    // você pode ajustar as origens e raios se quiser
    int rCone = 1, cCone = 7, raioCone = 3;
    habilidade_cone(tab, rCone, cCone, raioCone);
    print_tab(tab, "Depois do CONE (5 = area de efeito)");

    int rCruz = 5, cCruz = 1, raioCruz = 4;
    habilidade_cruz(tab, rCruz, cCruz, raioCruz);
    print_tab(tab, "Depois da CRUZ");

    int rOct = 7, cOct = 7, raioOct = 3;
    habilidade_octaedro(tab, rOct, cOct, raioOct);
    print_tab(tab, "Depois do OCTAEDRO (losango)");

    return 0;
}

