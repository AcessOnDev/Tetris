/*
    Jogo interativo Tetris implementado em linguagem C para uso no console (terminal de comandos)
    Para executar:
        >> start programa.exe
    Autor: Jefferson Campos
    Data: 28.08.2019 */
    
#include "tetris.h"
#include "display.h"
#define DEBUG 1

// Parte principal do programa, responsável por iniciar e chamar as funções auxiliares.
int main(){
    char matrix[ROWS][COLUMNS];
    Bloco tijolo;    
    int keypressed=0;

    //posicao inicial do personagem
    tijolo.i = 0;
    tijolo.j = COLUMNS/2;
    tijolo.tipo = TIPO_I;
    tijolo.orientacao= ORIENTACAO_LEFT;
    tijolo.width = 1;
    tijolo.height = 4;

    //inicializando matriz
    init(matrix);
    
    //apaga o cursor da tela
    ShowConsoleCursor(0);
    system("cls");

    //animaçao jogo
    while(keypressed!=ESC){
        gotoxy(0,0);

        #if DEBUG == 1
            printf("@ = (%d,%d)\n",tijolo.i,tijolo.j);
        #endif

        //posiçao do personagem na tela      
        drawbar(matrix,tijolo,PIXEL);
     
        //mostrar a matriz na tela
        printMatrix(matrix);

        //posiçao anterior do persogam ser apagada
        drawbar(matrix,tijolo,EMPTY);
       
        //movimentaçao queda
        if(tijolo.i<(ROWS-1)) tijolo.i++;

        //lendo teclas
        keypressed=0;        
        if(kbhit()) keypressed = getch();
        if(keypressed == ARROWS)keypressed = getch();
        switch(keypressed){
            case LEFT_A_A:
            case TECLA_A:
            case LEFT : 
                if(tijolo.j > 0)tijolo.j--; // Move Esquerda
            break;
            case RIGHT_D_D :
            case TECLA_D:
            case RIGHT : 
                if(tijolo.j < (COLUMNS-1)) tijolo.j++;  // Move Direita
            break;
            case TECLA_ESPACO:
                if(tijolo.orientacao == ORIENTACAO_RIGHT)
                    tijolo.orientacao = ORIENTACAO_UP;
                else
                    tijolo.orientacao++;
        }
    }
    system("pause");

    return 0;
}