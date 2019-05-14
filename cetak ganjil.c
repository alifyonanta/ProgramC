#include <stdio.h>
#include <conio.h>
int a,i,N,total=0;
main(){
    printf("Mencetak deret bil ganjil dari angka 1 s/d N\n");
    printf("Berapa dari :");scanf("%d",&a);
    printf("\nBerapa sampai :");scanf("%d",&N);
    for(i=a;i<=N;i++){
    if(i%2==1){
            printf("%d ",i);
            total+=i;
        }
    }
    printf("\njumlah = %i",total);

    getch();
}
