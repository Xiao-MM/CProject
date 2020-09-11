#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
/* 0 - 栈空 1 - 栈满*/
typedef struct LNode{
    ElemType value;
    struct LNode *next;
}LNode,*LinkedStack;

LinkedStack initStack(){
    LinkedStack S = (LNode*)malloc(sizeof(LNode));
    S->next = NULL; 
    return S;
}

ElemType pop(LinkedStack S){
    if (!S->next) return '0';
    ElemType value;
    LinkedStack q = S->next;
    value = q->value;
    S->next = q->next;
    free(q);
    return value;
}
void push(LinkedStack S,ElemType value){
    LinkedStack p = (LinkedStack)malloc(sizeof(LNode));
    p->value = value;
    p->next = S->next;
    S->next = p;
}
//0-栈非空 1-栈空
int isEmpty(LinkedStack S){
    if (!S->next) 
        return 1;
    else 
        return 0;  
}
void destoryStack(LinkedStack S){
    LinkedStack p = S;
    while (p){
        LinkedStack q = p->next;
        free(p);
        p = q;
    }
    S = NULL;  
}
void printStack(LinkedStack S){
    LinkedStack p = S->next;
    while (p){
        printf("%c,",p->value);
        p = p->next;
    }
}
int main(){
    LinkedStack S = initStack();
    printf("是否为空 ：%d\n",isEmpty(S));
    push(S,'a');
    push(S,'b');
    printStack(S);
    printf("\n");
    ElemType data = pop(S);
    printf("出栈元素为： %c",data);
    printf("\n");
    push(S,'c');
    push(S,'d');
    printStack(S);
    printf("\n");
    printf("是否为空 ：%d\n",isEmpty(S));
    destoryStack(S);
    printf("销毁后是否存在 ：%d\n",S==NULL);
    
}
