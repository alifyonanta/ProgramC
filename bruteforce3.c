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
