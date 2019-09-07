#include<stdio.h>

int fibo(int x);
void cetak(int x);

int main(){
    printf("MENCETAK FIBONACCI\n");
    cetak(10);
    return 0;
}

int fibo(int x){
if(x==0){
    return 0;
}if(x==1){
    return 1;
}if(x>1){
    return fibo(x-1)+fibo(x-2);
}
}

void cetak(int x){
    if(x>1){
    cetak(x-1);
    printf(" %i ",fibo(x));
    }
}
