#include "header.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

extern FILE *inputd;
extern FILE *outputd;


char* fair_d(char* s,char* k, int n){

char c1,c2;
int a,b;
for(int i = 0;i <= n;i += 2){
c1 = *(s + i);
c2 = *(s + i + 1);
a = search(c1,k);
b = search(c2,k);
if(a%8 == b%8){
if((a/8 == 0)&&(b/8 == 0)){
c1 = *(k + ((a)%8 + (7)*8));
c2 = *(k + ((b)%8 + (7)*8));
*(s + i) = c1;
*(s + i + 1) = c2;
}

else if((b == 0)||(a == 0)){
if(a/8 == 0){
c1 = *(k + ((a)%8 + (7)*8));
c2 = *(k + ((b)%8 + (b/8 - 1)*8));
*(s + i) = c1;
*(s + i + 1) = c2;
}
else if(b/8 == 0){
c1 = *(k + ((a)%8 + (a/8 - 1)*8));
c2 = *(k + ((b)%8 + (7)*8));
*(s + i) = c1;
*(s + i + 1) = c2;
}
}

else{
c1 = *(k + ((a)%8 + (a - 1)*8));
c2 = *(k + ((b)%8 + (b - 1)*8));
*(s + i) = c1;
*(s + i + 1) = c2;
}
}

else if(a/8 == b/8){
if((a%8 == 0)&&(b%8 == 0)){
c1 = *(k + (7 + (a/8)*8));
c2 = *(k + (7 + (b/8)*8));
*(s + i) = c1;
*(s + i + 1) = c2;
}
else if((a%8 == 0)||(b%8 == 0)){
if(a%8 == 0){
c1 = *(k + (7 + (a/8)*8));
c2 = *(k + (b%8 - 1 + (b/8)*8));
*(s + i) = c1;
*(s + i + 1) = c2;
}
else{
c1 = *(k + (a%8 - 1 + (a/8)*8));
c2 = *(k + (7 + (b/8)*8));
*(s + i) = c1;
*(s + i + 1) = c2;
}
}

else{
c1 = *(k + (a%8 - 1 + (a/8)*8));
c2 = *(k + (b%8 - 1 + (b/8)*8));
*(s + i) = c1;
*(s + i + 1) = c2;
}
}

else{
if(a < b){
c1 = *(k + (a%8 - 1 + (b/8)*8));
c2 = *(k + (b%8 - 1 + (a/8)*8));
*(s + i) = c1;
*(s + i + 1) = c2;
}
else{
c1 = *(k + b);
c2 = *(k + a);
*(s + i) = c1;
*(s + i + 1) = c2;
}
}
  
}
return s;
}


char* unpack(char *p){

int count = 1;
char d;
d = fgetc(inputd);

if(((d >= 48) && (d <= 57))||((d >= 65) && (d <= 90))||((d >= 97) && (d <= 122))||(d == '`')){
*p = d;
while(((d >= 48) && (d <= 57))||((d >= 65) && (d <= 90))||((d >= 97) && (d <= 122))||(d == '`')){
d = fgetc(inputd);
count++;
p = (char *)realloc(p,count*sizeof(char));
*(p + count - 1) = d;
}
return p;
}

else if(d == '~') 
{
count++;
p = (char *)realloc(p,count*sizeof(char));
*(p) = '~';
*(p + 1) = d;
return p;
}

else if((d == ' ')||(d == '\t')||(d == '\n')){
*p = d;
return p;
}

else if(d == EOF){
*p = d;
return p;
}
}

void decrypt(char *k){
char *s;
char *b;
char *c;
s = (char *)malloc(sizeof(char));
b = (char *)malloc(2*sizeof(char));
c = (char *)malloc(sizeof(char));
while(*(s = unpack(s)) != EOF){
if(strlen(s) == 1){
printf("%c",*s);
fputc(*s,outputd);
}
else if(strlen(s) == 2){
if(*s == '~'){
for(int i = 0; i<strlen(s); i++)
fputc(s[i],outputd);
}
else{
s = fair_d(s,k,strlen(s));
for(int i = 0;i<strlen(s);i++)
fputc(s[i],outputd);
}
}
else if(strlen(s) > 2){
if(*(s + strlen(s) -1) == '`'){
c = (char *)realloc(c,(strlen(s) -2)*sizeof(char));
c = strncpy(c,s,(strlen(s) -2));
c = fair_d(c,k,(strlen(s) -1));
for(int i = 0;i<(strlen(s)-1);i++)
fputc(c[i],outputd);
fputc(s[strlen(s) - 2],outputd);
printf("%s",s);
}
else{
s = fair_d(s,k,(strlen(s) -1));
for(int i = 0;i<strlen(s);i++)
fputc(c[i],outputd);
}
}
}
free(c);
free(k);
free(s);
free(b);
fclose(inputd);
fclose(outputd);
}
