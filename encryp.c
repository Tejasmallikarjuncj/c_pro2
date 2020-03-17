#include "header.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

extern FILE *input;
extern FILE *output;

int search(char c, char *k){
for(int i = 0; i < strlen(k);i ++){
if(c == *(k + i)){
return i;
}
}
}


char* fair_p(char* s,char* k, int n){

char c1,c2;
int a,b;
for(int i = 0;i <= n;i += 2){
c1 = *(s + i);
c2 = *(s + i + 1);
a = search(c1,k);
b = search(c2,k);
if(a%8 == b%8){
c1 = *(k + ((a)%8 + (a/8 + 1)*8));
c2 = *(k + ((b)%8 + (b/8 + 1)*8));
*(s + i) = c1;
*(s + i + 1) = c2;
}

else if(a/8 == b/8){
c1 = *(k + ((a + 1)%8 + (a/8)*8));
c2 = *(k + ((b + 1)%8 + (b/8)*8));
*(s + i) = c1;
*(s + i + 1) = c2;
}

else{
if(a < b){
c1 = *(k + (7 + (b/8)*8));
c2 = *(k + ((b)%8 + (a/8)*8));
*(s + i) = c1;
*(s + i + 1) = c2;
}
else{
c1 = *(k + ((a)%8 + (b/8)*8));
c2 = *(k + (7 + (a/8)*8));
*(s + i) = c1;
*(s + i + 1) = c2;
}
}
  
}
return s;
}


char* pack(char *p){

int count = 1;
char d;
d = fgetc(input);

if(((d >= 48) && (d <= 57))||((d >= 65) && (d <= 90))||((d >= 97) && (d <= 122))){
*p = d;
while(((d >= 48) && (d <= 57))||((d >= 65) && (d <= 90))||((d >= 97) && (d <= 122))){
d = fgetc(input);
count++;
p = (char *)realloc(p,count*sizeof(char));
*(p + count - 1) = d;
}
}

else if(((d >= 33) && (d <= 47))||((d >= 58) && (d <= 64))||((d >= 91) && (d <= 95))||((d >= 123) && (d <= 125))) 
{
count++;
p = (char *)realloc(p,count*sizeof(char));
*(p) = '~';
*(p + 1) = d;
}

else if((d == ' ')||(d == '\t')||(d == '\n')){
*p = d;}

else if(d == EOF){
*p = d;
}

return p;
}

void encrypt(char *k){
char *s;
char *b;
char *c;
s = (char *)malloc(sizeof(char));
b = (char *)malloc(2*sizeof(char));
c = (char *)malloc(sizeof(char));
while(*(s = pack(s)) != EOF){
if(strlen(s) == 1){
fputc(*s,output);
}
else if(strlen(s) == 2){
for(int i = 0; i<strlen(s); i++)
fputc(s[i],output);
}
else if(strlen(s) > 2){
if(strlen(s)%2 == 1){
*(b) = *(s + strlen(s) - 1);
*(b + 1) = '`';
c = (char *)realloc(c,(strlen(s)-1)*sizeof(char));
c = strncpy(c,s,strlen(s)-1);
c = fair_p(c,k,(strlen(s)-1));
for(int i = 0;i<(strlen(s) - 1);i++){
fputc(c[i],output);
}
fputc(b[0],output);
fputc(b[1],output);
}
else{
s = fair_p(s,k,strlen(s));
for(int i = 0;i<strlen(s);i++)
fputc(s[i],output);
}
}
}
free(c);
free(k);
free(s);
free(b);
fclose(input);
fclose(output);
}
