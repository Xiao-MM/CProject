#include<stdio.h>
#include<string.h>
int main(){
    char str1[12] = "hello";
    char *str2 = "world";
    char str3[12] = {'c','o','o','l'};
    char str4[10] = "llo";
    char str5[4] = {'h','a','n','\0'};
    printf("%lu,%lu,%lu\n",strlen(str1),strlen(str2),strlen(str3)); 
    strcat(str1,str2);
    printf("%s\n",str1);
    printf("%s\n",strstr(str1,str4));
    printf("%s\n",str5);
    return 0;
}