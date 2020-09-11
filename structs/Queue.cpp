#include<iostream>
#define MAX_SIZE 5
using namespace std;
typedef int ElemType;
/* 
 * 循环队列
 * 牺牲一个单元格判满
*/
typedef struct{
    ElemType data[MAX_SIZE];
    int front,rear;
}SqQueue;

void InitQueue(SqQueue &Q){
    Q.front = Q.rear = 0;
    for (int i = 0; i < MAX_SIZE; i++){
       Q.data[i] = 0;
    }
    cout<<"初始化完毕！"<<endl;
}

bool isEmpty(SqQueue Q){
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}
bool EnQueue(SqQueue &Q,ElemType x){
    if ((Q.rear+1)%MAX_SIZE == Q.front) return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1)%MAX_SIZE;
    return true;
}
bool DeQueue(SqQueue &Q,ElemType &x){
    if (Q.front == Q.rear) return false;
    x = Q.data[Q.front];
    Q.data[Q.front] = 0;
    Q.front = (Q.front+1)%MAX_SIZE;
    return true;
}
void printQueue(SqQueue Q){
    for (int i = 0; i < MAX_SIZE; i++){
        cout<<Q.data[i]<<" ";
    }
    cout<<endl;
}
int main(){
    SqQueue Q;
    InitQueue(Q);
    cout<<"当前队列是否为空："<<isEmpty(Q)<<endl;
    EnQueue(Q,1);
    printQueue(Q);
    int value;
    DeQueue(Q,value);
    cout<<"当前出队元素为："<<value<<endl;
    EnQueue(Q,2);
    EnQueue(Q,3);
    EnQueue(Q,4);
    printQueue(Q);
    DeQueue(Q,value);
    printQueue(Q);
    EnQueue(Q,5);
    EnQueue(Q,6);
    printQueue(Q);
    EnQueue(Q,7);
    printQueue(Q);
    DeQueue(Q,value);
    printQueue(Q);
    EnQueue(Q,7);
    printQueue(Q);
}

