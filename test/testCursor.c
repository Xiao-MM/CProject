#include<stdio.h>
int main(){
    int val = 10; /*实际变量的声明*/
    int *cursor;    /*指针变量的声明*/
    
    cursor = &val;//在指针变量中存储val的地址
    printf("Address of var variable:%p\n",&val);
    //"%p"打印指针,"%d"打印字符串
    //在指针变量中存放的地址
    printf("Address of cursor variable:%p\n",cursor);
    //指针指向变量的值
    printf("Value of *cursor variable:%d\n",*cursor);

    int *p=NULL;
    if (!p)
    printf("%p\n",p);

}