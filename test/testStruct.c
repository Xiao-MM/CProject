#include<stdio.h>
#include<string.h>
struct Book{
    char name[50];
    double price;
} book = {"好书",10.5};

struct Demo{
    int a;
    char b;
    double c;
};

typedef struct{
    int a;
    char b[50];
}Demo2;

typedef struct{
    char list[50];
    struct Demo demo;
}Demo3;

typedef struct 
{
    char list[50];
    Node *next;
}Node;

int main(){
    struct Demo demo;
    Demo2 demo2;
    demo2.a = 10;
    strcpy(demo2.b,"优秀");
}
