#include<iostream>
using namespace std;
typedef int ElemType;

typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct{
    LinkNode *front,*rear;
}LinkQueue;

void InitQueue(LinkQueue &Q){
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}
bool isEmpty(LinkQueue Q){
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}
//Q.rear始终指向队列最后一个元素（除了空值）
bool EnQueue(LinkQueue &Q,ElemType x){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;//将当前节点挂在队列结尾
    Q.rear = s;//将指针后移
    return true;
}
//Q.front始终指向头结点
bool DeQueue(LinkQueue &Q,ElemType &x){
    if (Q.front == Q.rear) return false;//队空
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (p == Q.rear) Q.rear = Q.front;//若只有一个元素，则将出队后的rear指针指向头结点
    free(p);
    return true;
}

void printQueue(LinkQueue Q){
    LinkNode *p = Q.front->next;
    while (p){
       cout<<p->data<<" ";
       p=p->next;
    }
    cout<<endl;
}
// int main(){
//     LinkQueue Q;
//     InitQueue(Q);
//     cout<<"当前队列是否为空："<<isEmpty(Q)<<endl;
//     EnQueue(Q,1);
//     printQueue(Q);
//     int value;
//     DeQueue(Q,value);
//     cout<<"当前出队元素为："<<value<<endl;
//     EnQueue(Q,2);
//     EnQueue(Q,3);
//     EnQueue(Q,4);
//     printQueue(Q);
//     DeQueue(Q,value);
//     printQueue(Q);
//     EnQueue(Q,5);
//     EnQueue(Q,6);
//     printQueue(Q);
//     EnQueue(Q,7);
//     printQueue(Q);
//     DeQueue(Q,value);
//     printQueue(Q);
//     EnQueue(Q,7);
//     printQueue(Q);
// }