#include <stdio.h>
int i,j,k;
char* nama[100];
typedef struct{
    char* nama[100];
    int no;
    char* status[100];
}M1;//Tipe Bentukan Member
typedef struct{
    char* nama[100];
    int sesi,harga,member;
}L1;//Tipe Bentukan Lapangan
M1 DMember[101];
L1 DLapangan1[13],DLapangan2[13];
int pilihanMember,pilihanLapangan,sesi;
char* statusMember[100];
