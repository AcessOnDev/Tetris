/*  Jogo interativo Tetris implementado em linguagem C para uso no console (terminal de comandos).
    Autor: Jefferson Campos
    Data: 28.08.2019 */

#include "tetris.h"

// Inicializa a matriz principal com espaços vazios.
void init(char matrix[ROWS][COLUMNS]){
    int i,j;

    for(i=0; i<ROWS; i++){
        for(j=0; j<COLUMNS; j++){
            matrix[i][j] =' ';
        }
    }
}

// Mostra o conteúdo da matriz principal na tela do computador.
void printMatrix(char matrix[ROWS][COLUMNS]){
    int i,j;
    
    //linhca cima
    for (j=0;j<COLUMNS-1;j++){
        printf("*");
    }
    //Matriz
        for(i=0; i<ROWS; i++){

            printf("*");                      
            for(j=0; j<COLUMNS-2; j++){                                    
                printf("%c", matrix[i][j]);
            }           
            printf("*\n");      
    }
    
    //linha de cima
     for (j=0;j<COLUMNS;j++){
        printf("*");
    }
}