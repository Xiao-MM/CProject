#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;

typedef struct BiNode{
    ElemType value;
    int flag;//标志该节点是第几次被访问
    struct BiNode *lchild;
    struct BiNode *rchild;
}BiNode,*BiTree;

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
int main(){
    BiTree T = createTree();
    preOrder(T);
    printf("\n");
    inOrder(T);
    printf("\n");
    postOrder(T);
    printf("\n");
    return 0;
}

