// Jogo interativo Tetris implementado em linguagem C para uso  no console (terminal de comandos).
/*  Autor: Jefferson Campos
    Data: 28/08/2019 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Configuração das dimensões da matriz principal do jogo
#define COLUMNS 20
#define ROWS 40
//configuracao de teclas
#define ESC 27
#define ARROWS 224
#define LEFT 75
#define RIGHT 77
#define TECLA_A 97
#define TECLA_D 100
#define LEFT_A_A 65
#define RIGHT_D_D 68
#define TECLA_ESPACO 32

//Orientação das Peças
#define ORIENTACAO_UP 1
#define ORIENTACAO_LEFT 2
#define ORIENTACAO_DOWN 3
#define ORIENTACAO_RIGHT 4

//Tipos de Peças
#define TIPO_L 1
#define TIPO_L_R 2 // L - Reverso
#define TIPO_T 3
#define TIPO_Z 4
#define TIPO_Z_R 5 // Z - Reverso
#define TIPO_O 6
#define TIPO_I 7

//Configuraçoes de layout
#define PIXEL 219
#define EMPTY 32

//Estrutura padrao de componentes
typedef struct{
    int i;  //posiçao linhas na matriz
    int j;  //posiçao linhas na matriz
    int orientacao; //orientaçao da peça
    int tipo;   //Tipo das peças( 7 peças)
    int width;  //Largura Peças
    int height; //Altura Peças
}Bloco;

// Inicializa a matriz principal com espaços vazios.
void init(char matrix[ROWS][COLUMNS]);

// Mostra o conteúdo da matriz principal na tela do computador.
void printMatrix(char matrix[ROWS][COLUMNS]);

//desenha uma barra usando simbolo de caracter ASCII ,passado por paramentros.
void drawbar(char matrix[ROWS][COLUMNS],Bloco barra,int simbolo);

// inicia a peça barra
void initBar(Bloco *barra);

//rotacioana o loco do jogo
void rotate(Bloco *bloco);

//verifica a colisao de blocos
int collisionDetect(char matrix[ROWS][COLUMNS],Bloco barra);