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
