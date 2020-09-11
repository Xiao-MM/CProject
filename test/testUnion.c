#include<stdio.h>
union Data{
    int i;
    float f;
    char str[9];
    double d;
}data;
int main(){
    printf("%d\n",sizeof(data));
}