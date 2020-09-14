#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef char ElemType;

typedef struct BiNode{
    ElemType value;
    int flag;//标志该节点是第几次被访问
    struct BiNode *lchild;
    struct BiNode *rchild;
}BiNode,*BiTree;
/*-----------------------Queue-----------------------*/
typedef struct LinkNode{
    BiNode *data;
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
bool EnQueue(LinkQueue &Q,BiNode *x){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;//将当前节点挂在队列结尾
    Q.rear = s;//将指针后移
    return true;
}
//Q.front始终指向头结点
bool DeQueue(LinkQueue &Q,BiNode* &x){
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

/*-----------------------Stack-----------------------*/
typedef struct LNode{
    BiTree data;
    struct LNode *next;
}LNode,*LiStack;

/*初始化栈*/
LiStack initStack(){
    //头结点
    LiStack S = (LNode*)malloc(sizeof(LNode));
    S->next = NULL; 
    return S;
}
/*出栈*/
BiTree pop(LiStack S){
    if (!S->next){
       return NULL;
    }
    BiTree data;
    LiStack q = S->next;
    data = q->data;
    S->next = q->next;
    free(q);
    return data;
}
/*取栈顶元素*/
BiTree get(LiStack S){
    return S->next->data;
}
/*入栈*/
void push(LiStack S,BiTree data){
    LiStack p = (LiStack)malloc(sizeof(LNode));
    p->data = data;
    p->next = S->next;
    S->next = p;
}
/*创建树*/
BiTree createTree(){
    char value;
    BiTree T;
    scanf("%c",&value);
    if (value == '#') T = NULL;
    else{
        T = (BiTree)malloc(sizeof(BiNode));
        T->value = value;
        T->lchild = createTree();
        T->rchild = createTree();
    }
    return T;
}
void visit(BiTree T){
    printf("%c ",T->value);
}
/*先序遍历非递归*/
void preOrder(BiTree T){
    LiStack S = initStack();
    BiTree p = T;
    while (p||S->next){
        if (p){
            //入栈时访问
            push(S,p);
            visit(p);
            p = p->lchild;
        }else{
            p = pop(S);
            p = p->rchild;
        }
    }   
}
/*中序遍历非递归*/
void inOrder(BiTree T){
    LiStack S = initStack();
    BiTree p = T;
    while (p||S->next){
        if (p){
            push(S,p);
            p = p->lchild; 
        }else{
            //出栈时访问
            p = pop(S);
            visit(p);
            p = p->rchild; 
        }    
    }
}
/*后序遍历非递归*/
void postOrder(BiTree T){
    LiStack S = initStack();
    BiTree p = T;
    while (p||S->next){
        //如果p不为空，则将其和其所有左孩子入栈
        if (p){
            p->flag = 1;
            push(S,p);
            p = p->lchild;
        }else{
            //如果p为空，则取栈顶元素(并没有pop)，如果是访问过一次，就将其右孩子入栈
            if (get(S)->flag == 1){
                p = get(S);
                p->flag = 2;//置访问次数为2
                p = p->rchild;//指针指向右孩子(不为空就入栈了)，为空则继续回退判断
            }else{
                //p为空且栈顶元素已经被访问了2次
                p = pop(S);//出栈
                visit(p);//访问
                p = NULL;//置指针为空，继续回退
            }
        }
    }
}
void levelOrder(BiTree T){
    BiNode *p = T;
    LinkQueue Q;
    InitQueue(Q);
    if (p){
        EnQueue(Q,p);
        while (!isEmpty(Q)){
            DeQueue(Q,p);
            visit(p);
            if (p->lchild)
                EnQueue(Q,p->lchild);
            if (p->rchild)
                EnQueue(Q,p->rchild);
        }
    }
}

int main(){
    BiTree T = createTree();
    cout<<"先序遍历：";
    preOrder(T);
    cout<<endl;
    cout<<"中序遍历：";
    inOrder(T);
    cout<<endl;
    cout<<"后序遍历：";
    postOrder(T);
    cout<<endl;
    cout<<"层次遍历：";
    levelOrder(T);
    cout<<endl;
    return 0;
}

