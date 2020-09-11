#include<stdio.h>
void swap1(int *a,int *b);
void swap2(int a,int b);
int main(int argc, char *argv[]){
    int a = 1;
    int b = 2;
    //swap1(&a,&b);
    // a = a ^ b;
    // b = a ^ b;
    // a = a ^ b;
    swap2(a,b);
    printf("a=%d,b=%d\n",a,b);
    return 0;
}
void swap1(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swap2(int a,int b){
    int temp = a;
    a = b;
    b = temp;
}
