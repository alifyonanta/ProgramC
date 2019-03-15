#include<stdio.h>
#include<string.h>

struct mahasiswa{
  char nama[100];
  char nim[11];
  int nilai,i;
  char grade;
}a[2];

void cek(int i,int nilai){
     if (nilai>=85){
           a[i].grade='A';
     }
     else if(nilai<85||nilai>=75){
           a[i].grade='B';
     }
     else if(nilai<75||nilai>=65){
           a[i].grade='C';
     }
     else if(nilai<65||nilai>=55){
           a[i].grade='D';
     }
     else{
           a[i].grade='E';
     }
}
void main(){
    int i;
     for(i=0;i<3;i++){
           printf("\n\nMAHASISWA KE - %d\n",i+1);
           printf("Masukan nama mahasiswa : ");
           scanf("%s",&a[i].nama);fflush(stdin);

           do{
                printf("Masukan nim mahasiswa [harus 10]:");
                scanf("%s",a[i].nim);fflush(stdin);
           }while(strlen(a[i].nim)!=10);

           printf("Masukan nilai mahasiswa :");
           scanf("%d",&a[i].nilai);fflush(stdin);
           cek(i,a[i].nilai);
     }

     for(i=0;i<3;i++){
           printf("\n\nMahasiswa ke %d\n",i+1);
           printf("Nama : %s\n",a[i].nama);
           printf("NIM : %s\n",a[i].nim);
           printf("Nilai : %d\n",a[i].nilai);
           printf("Grade : %c\n",a[i].grade);
     }
}
