#include "header.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*---DECLARATION OF FILE POINTERS-----*/
FILE* input;
FILE* output;


/*---MAIN FUNCTION---*/


int main()
{
char i[50];
char o[50];
char *k;
char *s;
int l;
printf("Enter the file name to encrypted ");
scanf("%s",i);
input = fopen(i,"r");
output = fopen("encpt.txt","w");
printf("Enter the lenght of the key ");
scanf("%d",&l);
char p[l];
printf("Enter the key ");
scanf("%s",p);
k = key(p);
encrypt(k);
}
