#include<iostream>
#include<string.h>
using namespace std;

typedef char ElemType;
typedef struct ThreadNode{
    ElemType data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;//0-指向的是孩子，1-指向的前驱或后继
}ThreadNode,*ThreadTree;

ThreadTree createTree(){
    char data;
    ThreadTree T = (ThreadTree)malloc(sizeof(ThreadNode));
    memset(T, 0, sizeof(ThreadNode));
    cin>>data;
    if (data == '#') T = NULL;
    else{
       // T = (ThreadTree)malloc(sizeof(ThreadNode));
        T->data = data;
        T->lchild = createTree();
        T->rchild = createTree();
    }
    return T;
}
//线索化
void InThread(ThreadTree p,ThreadTree &pre){
    if (p){
        InThread(p->lchild,pre);
        if (!p->lchild){
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre && !pre->rchild){
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->rchild,pre);
    }
}
//创建线索二叉树
void CreateInThread(ThreadTree T){
    ThreadTree pre = NULL;
    if (T){
        InThread(T,pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

ThreadNode* FirstNode(ThreadTree T){
    ThreadNode *p = T;
    while (!p->ltag){
        p = p->lchild;
    }
    return p;  
}
ThreadNode* NextNode(ThreadTree T){
    ThreadNode *p = T;
    if (p->rtag)
        p = p->rchild;
    else
        p = FirstNode(p->rchild);
    return p;
}

void ThreadInOrder(ThreadTree T){
    ThreadNode *p;
    for (p = FirstNode(T);p;p = NextNode(p))
        cout<<p->data<<" ";
    cout<<endl;
}

int main(){
    //----------错误-------------
    ThreadTree T = createTree();
    CreateInThread(T);
    ThreadNode *p = T->rchild;
    ThreadInOrder(T);
    cout<<p->data<<"--"<<p->rtag<<endl;
}