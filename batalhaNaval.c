#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Os navios são gerados aleatoriamente, fazendo um loop infinito até encontrar uma posição vaga par ao navio

int main() {
    int tabuleiro[10][10];

    // Inicializar toda a matriz com 0 (zero) indicando água
    for (int i=0; i<10;i++) {
        for (int j=0; j<10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Adicionando o primeiro navio na horizontal (Gerando aleatoriamente)
    srand(time(0));
    int navioHorizontal_X = rand() % 8; // %8 garante que não ultrapasse a matriz
    int navioHorizontal_Y = rand() % 8;

    printf("Coordenadas do navio horizontal:\n");
    for (int i=0; i<3; i++) {
        printf("(%d, %d)\n", navioHorizontal_Y, navioHorizontal_X + i);
        tabuleiro[navioHorizontal_Y][navioHorizontal_X + i] = 3;
    }

    // Adicionando o segundo navio na vertical (Gerando aleatoriamente)
    int navioVertical_Y, navioVertical_X;
    while (1) {
        navioVertical_X = rand() % 8;
        navioVertical_Y = rand() % 8;

        int podeAdicionar = 1; // Flag para verificar se é possível posicionar o navio

        // Verificar se há espaços vazios para o navio (sem sobreposição)
        for (int i=0; i<3; i++) {
            if (tabuleiro[navioVertical_Y + i][navioVertical_X] == 3) {
                podeAdicionar = 0;
                break;
            }
        }

        if (podeAdicionar) {
            break;
        }
    }

    printf("Coordenadas do navio vertical:\n");
    for (int i=0; i<3; i++) {
        printf("(%d, %d)\n", navioVertical_Y + i, navioVertical_X);
        tabuleiro[navioVertical_Y + i][navioVertical_X] = 3;
    }
    

    // Adicionando o terceiro navio na diagonal secundária (Gerando aleatoriamente)
    int navioDiagonalSecundaria_Y, navioDiagonalSecundaria_X;
    while (1) {
        navioDiagonalSecundaria_X = rand() % 8 + 2;
        navioDiagonalSecundaria_Y = rand() % 8;

        int podeAdicionar = 1; // Flag para verificar se é possível posicionar o navio

        // Verificar se há espaços vazios para o navio (sem sobreposição)
        for (int i=0; i<3; i++) {
            if (tabuleiro[navioDiagonalSecundaria_Y + i][navioDiagonalSecundaria_X - i] == 3) {
                podeAdicionar = 0;
                break;
            }
        }

        if (podeAdicionar) {
            break;
        }
    }

    printf("Coordenadas do navio diagonal secundária:\n");
    for (int i=0; i<3; i++) {
        printf("(%d, %d)\n", navioDiagonalSecundaria_Y + i, navioDiagonalSecundaria_X - i);
        tabuleiro[navioDiagonalSecundaria_Y + i][navioDiagonalSecundaria_X - i] = 3;
    }

    // Adicionando o quarto navio na diagonal primária (Gerando aleatoriamente)
    int navioDiagonalPrimaria_Y, navioDiagonalPrimaria_X;
    while (1) {
        navioDiagonalPrimaria_X = rand() % 8;
        navioDiagonalPrimaria_Y = rand() % 8;

        int podeAdicionar = 1; // Flag para verificar se é possível posicionar o navio

        // Verificar se há espaços vazios para o navio (sem sobreposição)
        for (int i=0; i<3; i++) {
            if (tabuleiro[navioDiagonalPrimaria_Y + i][navioDiagonalPrimaria_X + i] == 3) {
                podeAdicionar = 0;
                break;
            }
        }

        if (podeAdicionar) {
            break;
        }
    }

    printf("Coordenadas do navio diagonal primária:\n");
    for (int i=0; i<3; i++) {
        printf("(%d, %d)\n", navioDiagonalPrimaria_Y + i, navioDiagonalPrimaria_X + i);
        tabuleiro[navioDiagonalPrimaria_Y + i][navioDiagonalPrimaria_X + i] = 3;
    }
    
    printf("----- TABULEIRO NAVAL -----\n");
    printf("   A B C D E F G H I J\n");
    for (int i=0; i<10; i++) {
        printf("%2d", i+1);
        for (int j=0; j<10; j++) {
            if (tabuleiro[i][j] == 3) {
                printf(" \033[1;31m%d\033[0m", 3);
            } else {
                printf(" %d", 0);
            }
        }
        printf("\n");
    }
}