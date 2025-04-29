#include <stdio.h>

// Nível Mestre - O usuário descide a posição dos ataques

int main() {
    int tabuleiro[10][10];

    // Inicializar toda a matriz com 0 (zero) indicando água
    for (int i=0; i<10;i++) {
        for (int j=0; j<10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int opcaoAtaque;
    int ataque_X, ataque_Y;

    // Solicitar ao usuário o tipo de habilidade especial a ser usada
    printf("Informe o tipo do ataque: ");
    printf("\n1 - Cone");
    printf("\n2 - Losango");
    printf("\n3 - Cruz\nOpção: ");
    scanf("%d", &opcaoAtaque);
    
    // Solicita a posição central do ataque (entrada pelo usuário)
    printf("Informe a posição do ataque: ");
    scanf("%d %d", &ataque_X, &ataque_Y);

    // Ajusta a entrada do usuário (de 1-10 para 0-9, pois a matriz começa em 0)
    ataque_X--;
    ataque_Y--;

    int tamanhoCone, tamanhoLosango, tamanhoCruz;
    switch (opcaoAtaque) {
        case 1:
            // Cone
            tamanhoCone = 3;
            for (int i=0;i<tamanhoCone;i++) {
                for (int j=0; j<i*2+1; j++) {
                    // Calcula as coordenadas relativas ao centro do ataque
                    int pos_X = ataque_X - (i * 2 / 2) + j;
                    int pos_Y = ataque_Y - tamanhoCone/2 + i;

                     // Verifica se a posição está dentro dos limites da matriz
                    if (pos_X >= 0 && pos_X < 10 && pos_Y >= 0 && pos_Y < 10) {
                        tabuleiro[pos_Y][pos_X] = 3;
                    }
                }
            }

            break;
        case 2:
            // Losango
            tamanhoLosango = 3;
            for (int i=0; i<tamanhoLosango; i++) {
                int qtdCasas;

                // Define a quantidade de casas com base na simetria do losango
                if (i > tamanhoLosango / 2) {
                    qtdCasas = tamanhoLosango - i - 1;
                } else {
                    qtdCasas = i;
                }

                for (int j=0; j<qtdCasas*2+1; j++) {
                    int pos_X = ataque_X - (qtdCasas * 2 / 2) + j;
                    int pos_Y = ataque_Y - tamanhoLosango/2 + i;

                    if (pos_X >= 0 && pos_X < 10 && pos_Y >= 0 && pos_Y < 10) {
                        tabuleiro[pos_Y][pos_X] = 3;
                    }
                }
            }

            break;
        case 3:
            // Cruz
            tamanhoCruz = 3;
            for (int i=0; i<tamanhoCruz; i++) {
                // Linha central da cruz ocupa mais colunas
                for (int j=0; j < (i == tamanhoCruz/2 ? tamanhoCruz + 2 : 1); j++) {
                    int pos_X = ataque_X - j + (i == tamanhoCruz/2 ? (tamanhoCruz + 2) / 2 : 0);
                    int pos_Y = ataque_Y - tamanhoCruz/2 + i;

                    if (pos_X >= 0 && pos_X < 10 && pos_Y >= 0 && pos_Y < 10) {
                        tabuleiro[pos_Y][pos_X] = 3;
                    }
                }
            }

            break;
        default:
            printf("Opção Inválida.");
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