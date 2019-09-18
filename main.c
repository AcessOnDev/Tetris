/*
    Jogo interativo Tetris implementado em linguagem C para uso no console (terminal de comandos)
    Para executar:
        >> start programa.exe
    Autor: Jefferson Campos
    Data: 28.08.2019 */
    
#include "tetris.h"
#include "display.h"

// Parte principal do programa, responsável por iniciar e chamar as funções auxiliares.
int main(){
    char matrix[ROWS][COLUMNS];
    int posI, posJ;
    int keypressed=0;

    //posicao inicial do personagem
    posI = 0;
    posJ = COLUMNS/2;

    //inicializando matriz
    init(matrix);
    
    //apaga o cursor da tela
    ShowConsoleCursor(0);
    system("cls");

    //animaçao jogo
    while(keypressed!=ESC){
        gotoxy(0,0);

        //posiçao do personagem na tela 
        matrix[posI][posJ] = '@';

        //mostrar a matriz na tela
        printMatrix(matrix);
        matrix[posI][posJ] = ' ';        
        if(posI < (ROWS-1)) posI++;

        //lendo teclas
        keypressed=0;        
        if(kbhit()) keypressed = getch();
        if(keypressed == ARROWS)keypressed = getch();

        switch(keypressed){
            case LEFT_A_A:
            case TECLA_A:
            case LEFT : 
                if(posJ > 0)posJ--; // Move Esquerda
            break;
            case RIGHT_D_D :
            case TECLA_D:
            case RIGHT : 
                if(posJ < (COLUMNS-1)) posJ++;  // Move Direita
            break;

        }
    }
    system("pause");

    return 0;
}