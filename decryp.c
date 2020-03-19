#include "header.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

extern FILE *inputd;
extern FILE *outputd;


char* fair_d(char* s,char* k, int n){

char c1,c2;
int a,b;
for(int i = 0;i < n-1;i += 2){
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


else if((b/8 == 0)||(a/8 == 0)){
if(a/8 == 0){
c1 = *(k + ((a)%8 + (7)*8));
c2 = *(k + ((b)%8 + ((b/8) - 1)*8));
*(s + i) = c1;
*(s + i + 1) = c2;
}
else if(b/8 == 0){
c1 = *(k + ((a)%8 + ((a/8) - 1)*8));
c2 = *(k + ((b)%8 + (7)*8));
*(s + i) = c1;
*(s + i + 1) = c2;
}
}

else{
c1 = *(k + ((a)%8 + ((a/8) - 1)*8));
c2 = *(k + ((b)%8 + ((b/8) - 1)*8));
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
c1 = *(k + b);
c2 = *(k + a);
*(s + i) = c1;
*(s + i + 1) = c2;
//printf("%c  %c\n",c1,c2);
}
}
return s;
}


char* unpack(char *p, char *buf){

int count = 1;
char d;
p = (char *)realloc(p,sizeof(char)); 
if(strlen(buf) == 1){
*p = buf[0];
*(buf) = '\0';
*(buf + 1) = '\0';
return p;
}

else if(strlen(buf) == 2){
p = (char *)realloc(p,2*sizeof(char));
*p = buf[0];
*(p + 1) = buf[1];
*(buf) = '\0';
*(buf + 1) = '\0';
return p;
}

else{
d = fgetc(inputd);
if(((d >= 48) && (d <= 57))||((d >= 65) && (d <= 90))||((d >= 97) && (d <= 122))){
*p = d;
while((( d >= 48) && (d <= 57))||((d >= 65) && (d <= 90))||((d >= 97) && (d <= 122))||(d == '`')||(d == '~')){
d = fgetc(inputd);
count++;
p = (char *)realloc(p,count*sizeof(char));
*(p + count - 1) = d;
}
char b;
char c;
b = *(p + count - 2);
c = *(p + count - 1);
if(b == '~'){
*(buf) = '~';
*(buf + 1) = *(p + count - 1);
*(p + count - 1) = '\0';
*(p + count - 2) = '\0';
p = (char *)realloc(p,(count-2)*sizeof(char));
}
else if((c == ' ')||(c == '\t')||(c == '\n')||(c == EOF)){
*buf = c;
*(p + count - 1) = '\0';
p = (char *)realloc(p,(count-1)*sizeof(char));
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
}

void decrypt(char *k){
char *s;
char *b;
char *buf;
char *c;
//s = (char *)malloc(sizeof(char));
b = (char *)malloc(2*sizeof(char));
buf = (char *)malloc(2*sizeof(char));
c = (char *)malloc(sizeof(char));
while(*(s = unpack(s,buf)) != EOF){
//printf("%s\n",s);
if(strlen(s) == 1){
fputc(*s,outputd);
}
else if(strlen(s) == 2){
if(*s == '~'){
fputc(s[1],outputd);
}
else{
s = fair_d(s,k,strlen(s));
for(int i = 0;i<strlen(s);i++)
fputc(s[i],outputd);
}
}
else if(strlen(s) > 2){
if(*(s + strlen(s) -1) == '`'){
c = (char *)realloc(c,(strlen(s) - 2)*sizeof(char));
strncpy(c,s,(strlen(s) -2));
//printf("%s\n",c);
c = fair_d(c,k,strlen(c));
//printf("%s\n",c);
for(int i = 0;i<strlen(c);i++)
fputc(*(c + i),outputd);
char t = *(s + strlen(s) - 2);
fputc(t,outputd);
free(c);
//c = (char *)realloc(c,0);
}
else{
s = fair_d(s,k,strlen(s));
for(int i = 0;i<strlen(s);i++)
fputc(*(s + i),outputd);
}
}
//s = (char *)realloc(s,0);
}
free(c);
free(k);
free(s);
free(buf);
free(b);
fclose(inputd);
fclose(outputd);
}
