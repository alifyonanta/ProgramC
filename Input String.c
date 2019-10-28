#include <stdio.h>
#include <string.h>

int main (){
char a[50];

printf ("masukan kalimat : ");
scanf (" %49[^\n]",&a);
printf ("kalimat anda : %s",a);
return 0;
}
