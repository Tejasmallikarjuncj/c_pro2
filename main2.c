#include "header.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE* inputd;
FILE* outputd;


int main()
{
char i[50];
char o[50];
char *k;
char *s;
int l;
printf("Enter the file name to decrypted\n");
scanf("%s",i);
inputd = fopen(i,"r");
outputd = fopen("Decpt.txt","w");
printf("Enter the lenght of the key");
scanf("%d",&l);
char p[l];
printf("Enter the key");
scanf("%s",p);
k = key(p);
decrypt(k);
}