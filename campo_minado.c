#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void aleatorio(char jogo[8][8]);
void imprimir(char jogo[8][8]);
void subst(char coluna, int *col);
void escondido(char jogo[8][8], int linha, int col);
void verificar(char jogo[8][8], int linha, int col);

int main() {
    char jogo[8][8];
    int linha;
    char coluna;
    int col;

    printf("\t-------Campo minado--------\n\n\n\n");

    aleatorio(jogo);
    imprimir(jogo);

    escondido(jogo, linha, coluna);

    printf("Digite uma Linha: ");
    scanf("%d", &linha);
    linha -= 1;

    printf("Digite uma Coluna: ");
    scanf(" %c", &coluna);
    subst(coluna, &col);

    escondido(jogo, linha, col);
    verificar(jogo, linha, col);

    return 0;
}

void imprimir(char jogo[8][8]) {
    printf("     A    B    C    D    E    F    G    H\n");
    register int i, j;
    int num = 1;
    for (i = 0; i < 8; i++) {
        printf("  -----------------------------------------\n");
        printf("%d |", num++);
        for (j = 0; j < 8; j++) {
            printf("%4c|", jogo[i][j]);
        }
        printf("\n");
    }
    printf("  -----------------------------------------\n\n");
    Sleep(1200);
    system("CLS");
}

void aleatorio(char jogo[8][8]) {
    register int i, j = 0;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++)
            jogo[i][j] = ' ';
    }

    int c = 0;
    for (c = 0; c < 23;) {
        i = rand() % 8;
        j = rand() % 8;
        if (jogo[i][j] != '@') {
            jogo[i][j] = '@';
            c++;
        }
    }
}

void subst(char coluna, int *col) {

			if(coluna=='A'||coluna=='a')
				*col=0;
			else
				if(coluna=='B'||coluna=='b')
					*col=1;
				else
					if(coluna=='C'||coluna=='c')
						*col=2;
					else
						if(coluna=='D'||coluna=='d')
							*col=3;
						else
							if(coluna=='E'||coluna=='e')
								*col=4;
							else
								if(coluna=='F'||coluna=='f')
									*col=5;
								else
									if(coluna=='G'||coluna=='g')
										*col=6;
									else
										if(coluna=='H'||coluna=='h')
											*col=7;

}

void escondido(char jogo[8][8], int linha, int col) {
    int num = 1;
    register int i, j;

    printf("     A    B    C    D    E    F    G    H\n");

    for (i = 0; i < 8; i++) {
        printf("  -----------------------------------------\n");
        printf("%d |", num++);
        for (j = 0; j < 8; j++) {
            if (linha == i && col == j) {
                printf("%4c|", jogo[i][j]);
            } else {
                printf("    |");
            }
        }
        printf("\n");
    }
    printf("  -----------------------------------------\n\n");
}

void verificar(char jogo[8][8], int linha, int col) {
    if (jogo[linha][col] == '@') {
        printf("Voce perdeu\n");
    }
}
