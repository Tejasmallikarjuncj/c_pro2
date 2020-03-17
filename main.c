#include "header.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE* input;
FILE* output;

int main()
{
char i[50];
char o[50];
char *k;
int l;
printf("Enter the file name to encrypted\n");
scanf("%s",i);
input = fopen(i,"r");
output = fopen("encpt.txt","w");
printf("Enter the lenght of the key");
scanf("%d",&l);
char p[l];
printf("Enter the key");
scanf("%s",p);
k = key(p);
encrypt(k);
return 0;
}
