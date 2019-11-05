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
    Bloco tijolo;    
    int keypressed=0;

    //posicao inicial do personagem
    initBar(&tijolo);

    //inicializando matriz
    init(matrix);
    
    //apaga o cursor da tela
    ShowConsoleCursor(0);
    system("cls");

    //animaçao jogo
    while(keypressed!=ESC){
        gotoxy(0,0);

        #if DEBUG == 1
            printf("Posicao = (%d,%d)\n",tijolo.i,tijolo.j);
            printf("Dimensao = (%d,%d)\n",tijolo.width,tijolo.height);
        #endif

        //posiçao do personagem na tela      
        drawbar(matrix,tijolo,PIXEL);
     
        //mostrar a matriz na tela
        printMatrix(matrix);

        //posiçao anterior do persogam ser apagada
         if(!collisionDetect(matrix,tijolo)){
            drawbar(matrix,tijolo,EMPTY);       
       
            //movimentaçao queda
            if(tijolo.i<(ROWS-1)) tijolo.i++;

        }else{
            initBar(&tijolo);
        }
        //lendo teclas
        keypressed=0;        
        if(kbhit()) keypressed = getch();
        if(keypressed == ARROWS)keypressed = getch();
        switch(keypressed){
            case LEFT_A_A:
            case TECLA_A:
            case LEFT : 
                if(tijolo.j - (tijolo.width/2) > 0)tijolo.j--; // Move Esquerda
            break;
            case RIGHT_D_D :
            case TECLA_D:
            case RIGHT : 
                if(tijolo.j + (tijolo.width/2) < (COLUMNS-1)) tijolo.j++;  // Move Direita
            break;
            case TECLA_ESPACO:
                rotate(&tijolo);
            break;
        }
    }
    system("pause");

    return 0;
}