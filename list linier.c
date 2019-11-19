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

void alokasi(){
   printf("Nilai :");scanf("%s",&x[100]);
   p=(node*)malloc(sizeof(node));
   p->data=x[100];
   p->next==NULL;
}

void listawal(){
   int i,N;
   printf("masukkan banyak data awal :");scanf("%d",&N);
   for(i=0;i<N;i++){
      printf("masukkan nilai data ke-%d\n",i+1);
      alokasi();
      if(head==0){


         head=p;
         tail=p;
      }
      else{
         tail->next=p;
         tail=tail->next;
      }
   }
   cetak();
}

void insertfirst(){
   char pil;
   printf("masukkan nilai data yang akan di insert-kan di awal\n");
   do{
     alokasi();
     p->next=head;
     head=p;
     cetak();
     fflush(stdin);
     printf("inputkan data lagi ?");
     pil=getchar();
   }while(pil=='Y' || pil=='y');
}
