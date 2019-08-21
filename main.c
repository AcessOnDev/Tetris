#include <stdio.h>
#include <stdlib.h>
#define COLUMN 60
#define ROWS 25

void init(char matrix[ROWS][COLUMN]){
    int i,j;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLUMN;j++){
            matrix[i][j] =' ';
        }
    }

}
void printMatrix(char matrix[ROWS][COLUMN]){
     int i,j;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLUMN;j++){
            printf("%c",matrix[i][j]);
        }
        printf("\n");
    }

}

int main(){
    char matrix[ROWS][COLUMN];
    int posI,posJ;    

    posI = ROWS/2;
    posJ = COLUMN/2;    
    init(matrix);
    
    while(1){
        system("cls");        
        matrix[posI][posJ] ='@';
        printMatrix(matrix);

        matrix[posI][posJ] =' ';
        if(posJ < COLUMN) posJ++;        
    }
    system("pause");
    return 0;
}
