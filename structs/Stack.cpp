#include<iostream>
#define MAX_SIZE 10
using namespace std;

typedef int ElemType;
typedef struct{
    ElemType data[MAX_SIZE];
    int top;
}Stack;

void InitStack(Stack &S){
    for (int i = 0; i < MAX_SIZE; i++){
       S.data[i] = 0; 
    }
    S.top = -1;
}

bool Push(Stack &S, ElemType x){
    if (S.top == MAX_SIZE) return false;//栈满
    S.data[++S.top] = x;
    return true;
}

bool Pop(Stack &S, ElemType &x){
    if (S.top == -1) return false;
    x = S.data[S.top--];
    return true;
}

void printStack(Stack S){
    for (int i = 0; i < MAX_SIZE; i++){
       cout<<S.data[i]<<" "; 
    }
    cout<<endl;
}
int main(){
    Stack S;
    InitStack(S);
    printStack(S);
    for (int i = 1; i <= 4; i++){
       Push(S,i);
    }
    printStack(S);
    int value;
    Pop(S,value);
    cout<<"出栈的值为："<<value<<endl;
    Push(S,5);
    Push(S,6);
    printStack(S);
}