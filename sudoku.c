#include <stdio.h>

int isAvailable(int sudoku[][9], int row, int col, int num)
{
    int i, j;
    for(i=0; i<9; ++i)
        if( (sudoku[row][i] == num) || ( sudoku[i][col] == num )  )//checking in row and col
            return 0;

     //checking in the grid
    int rowStart = (row/3) * 3;
    int colStart = (col/3) * 3;

    for(i=rowStart; i<(rowStart+3); ++i)
    {
        for(j=colStart; j<(colStart+3); ++j)
        {
            if( sudoku[i][j] == num )
                return 0;
        }
    }

    return 1;
}
