#include <stdio.h>
#include <time.h>

struct{

static int iter = 0;    //menghitung jumlah iterasi
static int done = 0;    //boolean yang menandakan solve telah dicapai

void print(void) { //prosedur untuk mencetak sudoku
int x, y;
printf(“———————–\n”);
for (x = 0; x < 9; x++) {
for (y = 0; y < 9; y++) {
printf(“%d “, msudoku[x][y]);
if (y % 3 == 2) printf(“| “);
}
printf(“\n”);
if (x % 3 == 2) printf(“———————–\n”);
}
}
