#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include <string.h>

void alokasi();
void listawal();
void insertfirst();
void cetak();

typedef struct simpul node;
struct simpul{
    char* data;
    node *p,*next,*head,*tail;
};
node *p, *head, *after, *next,*tail;
char* x[100];

int main(){
   listawal();
   insertfirst();
   getch();
   return 0;
}
