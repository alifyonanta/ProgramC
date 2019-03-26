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
  
int number_validation(int row, int col, int n) {
//kamus
int x,y;

//algoritma
if (msudoku[row][col] == n) return 1; //periksa angka bernilai n pada kotak saat ini, jika sama, maka mengembalikan 1 (penempatan angka bisa dilakukan)
if (msudoku[row][col] != 0) return 0; //periksa angka bernilai n pada kotak saat ini, jika tidak bernilai 0, maka mengembalikan 0 (penempatan angka tidak bisa dilakukan)
for (x = 0; x < 9; x++) {
  if(msudoku[x][col] == n) return 0; //periksa baris, jika terdapat nilai yg sama dengan n, maka mengembalikan 0 (penempatan angka tidak bisa dilakukan)
}
for (y = 0; y < 9; y++) {
  if(msudoku[row][y] == n) return 0; //periksa kolom, jika terdapat nilai yg sama dengan n, maka mengembalikan 0 (penempatan angka tidak bisa dilakukan)
}
  if (check_minisquare(row,col,n)) return 0; //periksa pada  kotak kecil dari sudoku
  return 1;        //kasus selain diatas, tidak ada angka yang sama, maka mengembalikan 1 (penempatan angka bisa dilakukan)
}
  
int check_minisquare(int row, int col, int n) {
//kamus
int i, j, firstx, firsty;
 
int check_minisquare(int row, int col, int n) {
//kamus
int i, j, firstx, firsty;
  
//algoritma
if (row < 3) {
  firstx = 0;
if (col < 3) {
  firsty = 0;        //bagian kotak kecil kiri atas
} else if (col > 5) {
  firsty = 6;        //bagian kotak kecil kanan atas
} else {
  firsty = 3;        //bagian kotak kecil atas
  }
}
} else if (row > 5) {
  firstx = 6;
    if (col < 3) {
    firsty = 0;        //bagian kotak kecil kiri bawah
  } else if (col > 5) {
    firsty = 6;        //bagian kotak kecil kanan bawah
  }else{
    firsty = 3;        //bagian kotak kecil bawah
  }
  }else{
    firstx = 3;
  if (col < 3) {
  firsty = 0;        //bagian kotak kecil kiri
  } else if (col > 5) {
    firsty = 6;        //bagian kotak kecil kanan
  } else {
    firsty = 3;        //bagian kotak kecil tengah
  }
}

//periksa kotak kecil, apakah terdapat angka yang sama
for (i = firstx; i < (firstx + 3); i++)
for (j = firsty; j < (firsty + 3); j++)
if (msudoku[i][j] == n) return 1;
return 0;    //tidak terdapat angka yang sama pada kotak kecil
}
