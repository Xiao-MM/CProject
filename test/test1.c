#include <stdio.h>

int main(int argc, char **argv) {
        // const int a = 2;
        // int *b = (int *)&a;
        // *b = 5;
        // printf("%p, %p\n", &a, b);
        // printf("%d, %d, %d\n", a, *(&a), *b);
        char name[] = "zsx周";
        printf("%c,%c,%d,%s\n",name[0],name[1],name[2],&name[3]);
}