#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

int isAvailable(uint8_t puzzle[][9], uint8_t row, uint8_t col, uint8_t num)
{
    uint8_t rowStart;
    uint8_t colStart;
    uint8_t i;

    rowStart = (row/3) * 3;
    colStart = (col/3) * 3;

    for(i=0; i<9; ++i)
    {
        if (puzzle[row][i] == num) return 0;
        if (puzzle[i][col] == num) return 0;
        if (puzzle[rowStart + (i%3)][colStart + (i/3)] == num) return 0;
    }
    return 1;
}

int solveSudoku(uint8_t puzzle[][9], uint8_t row, uint8_t col)
{
    uint8_t i;

    if(row<9 && col<9)
    {
        if(puzzle[row][col])
        {
            if((col+1)<9) return solveSudoku(puzzle, row, col+1);
            else if((row+1)<9) return solveSudoku(puzzle, row+1, 0);
            else return 1;
        }
        else
        {
            for(i=0; i<9; ++i)
            {
                if(isAvailable(puzzle, row, col, i+1))
                {
                    puzzle[row][col] = i+1;
                    if(solveSudoku(puzzle, row, col)) return 1;
                    puzzle[row][col] = 0;
                }
            }
        }
        return 0;
    }
    else return 1;
}

int main(){
    //  Start timers
    struct timeval start, end;
    gettimeofday(&start, NULL);
    int i, j;
    int sudoku[9][9]={{0, 0, 0, 0, 0, 0, 0, 9, 0},
                      {1, 0, 0, 4, 7, 0, 6, 0, 8},
                      {0, 5, 2, 0, 1, 9, 4, 0, 7},
                      {2, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 1, 0, 7, 5, 0, 0, 0, 9},
                      {9, 0, 7, 3, 6, 4, 0, 8, 0},
                      {5, 0, 6, 0, 8, 1, 0, 7, 0},
                      {0, 8, 0, 0, 0, 0, 2, 0, 0}};

    if(solveSudoku(sudoku, 0, 0))
    {
        printf("\n+-----+-----+-----+\n");
        for(i=1; i<10; ++i)
        {
            for(j=1; j<10; ++j) printf("|%d", sudoku[i-1][j-1]);
            printf("|\n");
            if (i%3 == 0) printf("+-----+-----+-----+\n");
        }
    }
    else printf("\n\nTIDAK ADA SOLUSI\n\n");

    //  Stop timers
    gettimeofday(&end, NULL);
    double delta = ((end.tv_sec  - start.tv_sec) * 1000000u +
         end.tv_usec - start.tv_usec) / 1.e6;
    printf("\nCPU Time = %g \n",delta);

   return 0;
}

