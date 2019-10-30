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

//Main Program
int main(){

    printf("Masukkan Nama Anda :\n --> ");
    scanf("%s",&nama);
    system("cls");
    if(CekMember()==0){ //Jika belum menjadi member

        printf("Maaf Anda Belum Menjadi Member\nApakah Mau Menjadi Member ?\n1. Ya\n2. Tidak\n-->");
        scanf("%i",&pilihanMember);
        system("cls");
        if(pilihanMember==1){
            printf("Masukkan Status Anda\n-->");
            scanf("%s",&statusMember);
            system("cls");
            TambahMember();
        }else if(pilihanMember==2){
            cekLapangan();
            getch();
            system("cls");
            printf("Masukkan Jenis Lapangan\n1. Lapangan Vinyl\n2. Lapangan Sintesis\n->");
            scanf("%i",&pilihanLapangan);
            printf("Masukkan No Sesi\n->");
            scanf("%i",&sesi);
            TambahPesanan();
        }
    }else{
        pilihanMember=1;
        cekLapangan();
        getch();
        system("cls");
        printf("Masukkan Jenis Lapangan\n1. Lapangan Vinyl\n2. Lapangan Sintesis\n->");
        scanf("%i",&pilihanLapangan);
        printf("Masukkan No Sesi\n->");
        scanf("%i",&sesi);
        TambahPesanan();
    }
}

void DataMembertoC(){
    FILE *Member;
    Member=fopen("member.txt","a+");
    i=1;
    while(!feof(Member)){
        fscanf(Member,"%s %i %s",DMember[i].nama,&DMember[i].no,DMember[i].status);
        i++;
    }
}

int CekMember(){
    DataMembertoC();
    int ketemu=0;
    int Lokasi=0;
    for(i=1;i<=100;i++){
        if(strcmp(DMember[i].nama,nama)==0){
            ketemu=1;
            Lokasi=i;
            break;
        }
    }
        i=Lokasi;
        return ketemu;
}
