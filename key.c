#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*---FUNCTION FOR GENERATIING KEY SQUARE---*/


int check(char p,char *k)
{
int flag = 0;
int n = strlen(k);
for(int i = 0;i<n;i++){
if(p == *(k + i)){
flag = 1;
return 0;
}
}
if(flag == 0)
return 1;  
}

int search(char c, char *k){
for(int i = 0; i < strlen(k);i ++){
if(c == *(k + i)){
return i;
}
}
}

/*---KEY SQUARE GENERATION----*/

char* key(char *k)
{
int count = strlen(k);
char *p;
p = (char *)malloc(64*sizeof(char));
for(int i =0;i<count;i++)
*(p + i) = *(k + i);
for(int j = 48;j <= 57;j++){
if(check((char)j,k)){
*(p + count) = (char)j;
count++;
}
}

for(int j = 65;j <= 90;j++){
if(check((char)j,k)){
*(p + count) = (char)j;
count++;
}
}

for(int j = 97;j <= 122;j++){
if(check((char)j,k)){
*(p + count) = (char)j;
count++;
}
}
return p;
}
