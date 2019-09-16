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

    //posicao inicial do personagem
    posI = 0;
    posJ = COLUMNS/2;
    //inicializando matriz
    init(matrix);
    
    //apaga o cursor da tela
    ShowConsoleCursor(0);
    system("cls");
    //animaçao jogo
    while(1){
        gotoxy(0,0);
        //posiçao do personagem na tela 
        matrix[posI][posJ] = '@';
        //mostrar a matriz na tela
        printMatrix(matrix);
        matrix[posI][posJ] = ' ';        
        if(posI < (ROWS-1)) posI++;
    }
    system("pause");

    return 0;
}