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

void TambahMember(){
    FILE *Member;
    int NoMember;
    Member=fopen("member.txt","a+");
    DataMembertoC();
    if(DMember[1].no==NULL){
        NoMember=11000;
    }else{
        NoMember=DMember[i-2].no+1;
    }
    fprintf(Member,"%s %i %s\n",nama,NoMember,statusMember);
}

void TambahPesanan(){
    FILE *DL1;
    FILE *DL2;
    DL1=fopen("Data Lapangan Vinyl.txt","a+");
    DL2=fopen("Data Lapangan Sintesis.txt","a+");
    if(pilihanLapangan==1){
        if(pilihanMember==1){
                CekMember();
            fprintf(DL1,"%s\t%i\t%i\t%i\n",nama,sesi,135000,DMember[i].no);
        }
        if(pilihanMember==2){
            fprintf(DL1,"%s\t%i\t%i\t%i\n",nama,sesi,150000,0);
        }
//        fprintf(DL1,"%s\t%i\t%i\t%i\n",nama,sesi,harga,member);
    }else if(pilihanLapangan == 2){
        if(pilihanMember==1){
                CekMember();
            fprintf(DL2,"%s\t%i\t%i\t%i\n",nama,sesi,90000,DMember[i].no);
        }
        if(pilihanMember==2){
            fprintf(DL2,"%s\t%i\t%i\t%i\n",nama,sesi,100000,0);
        }
    }
//    fprintf(Member,"%s %i %s\n",nama,NoMember,statusMember);
}

void cekLapangan(){
    DataLapangan1();
    DataLapangan2();

    int ketemu1,ketemu2;
    printf("________________________________________________________\n");
    printf("Ketersediaan Lapangan 1 : \tKetersediaan Lapangan 2 : \n");
    for(i=1;i<13;i++){
        ketemu1=0;
        ketemu2=0;
        for(j=1;j<13;j++){
            if(DLapangan1[j].sesi==i){
                ketemu1=1;
            }
            if(DLapangan2[j].sesi==i){
                ketemu2=1;
            }
        }
        if(ketemu1==0){
            printf("Sesi Ke-%i = Kosong \t\t",i);
        }else{
            printf("Sesi Ke-%i = Ada \t\t",i);
        }
        if(ketemu2==0){
            printf("Sesi Ke-%i = Kosong \n",i);
        }else{
            printf("Sesi Ke-%i = Ada \n",i);
        }
    }
}
