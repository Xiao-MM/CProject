#include<stdio.h>
//函数外定义i,j
int i;
int j;
int add(){
    //函数内声明i,j为外部变量
    extern int i;
    extern int j;
    //为外部变量（全局变量）赋值
    i = 1;
    j = 2;
    return i+j;
}
int main(){
    int result = add();
    printf("%d\n",result);
    return 0;
}