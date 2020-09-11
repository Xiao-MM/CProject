#include<stdio.h>
int main(){
    int m = 1;
    int c ;
 //   ++m+m++;
    c = ++m+m++;
    printf("%d\n",m);
    printf("%d\n",c);
}