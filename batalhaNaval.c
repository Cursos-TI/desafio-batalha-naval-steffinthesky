#include <stdio.h>

void exibirTabuleiro(int tabuleiro[10][10], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void habilidadeCone(int matriz[5][5]) {
    int meio = 2;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j] = (j >= meio - i && j <= meio + i) ? 1 : 0;
        }
    }
}

void habilidadeCruz(int matriz[5][5]) {
    int meio = 2; // Centro da cruz
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j] = (i == meio || j == meio) ? 1 : 0;
        }
    }
}

void habilidadeOctaedro(int matriz[5][5]) {
    int meio = 2;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j] = (abs(meio - i) + abs(meio - j) <= 2) ? 1 : 0;
        }
    }
}

int main() {
    int tabuleiro[10][10] = {0}; 

    for (int i = 0; i < 3; i++) {
        tabuleiro[i][1] = 3;
    }

    for (int j = 0; j < 3; j++) {
        tabuleiro[4][j] = 3; 
    }

    printf("Tabuleiro com dois navios:\n");
    exibirTabuleiro(tabuleiro, 10);

    for (int i = 0; i < 3; i++) {
        tabuleiro[i][i] = 3; // Diagonal principal
        tabuleiro[i][9 - i] = 3; // Diagonal secundária
    }

    printf("Tabuleiro com quatro navios:\n");
    exibirTabuleiro(tabuleiro, 10);

    int habilidade[5][5];

    printf("Habilidade Cone:\n");
    habilidadeCone(habilidade);
    exibirTabuleiro(habilidade, 5);

    printf("Habilidade Cruz:\n");
    habilidadeCruz(habilidade);
    exibirTabuleiro(habilidade, 5);

    printf("Habilidade Octaedro:\n");
    habilidadeOctaedro(habilidade);
    exibirTabuleiro(habilidade, 5);

    return 0;
}
