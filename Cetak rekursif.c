#include<stdio.h>

void cetak(int arr[], int n){
    if(n>0){
       cetak(arr,n-1);
       printf("\nAngkanya = %d",arr[n-1]);
    }
}

void input(int arr[], int n){
    if(n>0){
       input(arr,n-1);
       printf("\nMasukkan angka : ");
       scanf("%d",&arr[n-1]);
    }
}
int total(int arr[], int n){
    if(n>0){
        return arr[n-1]+total(arr,n-1);
    }else{
        return n;
    }

}
int kurang(int arr[], int n){
    if(n>0){
        return arr[n-1]-kurang(arr,n-1);
    }else{
        return n;
    }
}

int main(){
    int a[100], size=5;
    input(a,size);
    cetak(a,size);
    printf("\nSUM = %d",total(a,size));
    printf("\nKURANG = %d",kurang(a,size));
    return 0;
}
