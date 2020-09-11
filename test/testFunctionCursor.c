#include<stdio.h>
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    size_t size;
    int (*p)(int,int) = &max;
    int c = p(p(3,2),5);
    printf("%d\n",c);
}