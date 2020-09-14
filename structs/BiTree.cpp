#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef struct BiNode{
    char value;
    struct BiNode *lchild;
    struct BiNode *rchild;    
}BiNode,*BiTree;

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
void preOrder(BiTree T){
    if (T)
    {
        printf("%c,",T->value);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}
void inOrder(BiTree T){
    if (T)
    {
        inOrder(T->lchild);
        printf("%c,",T->value);
        inOrder(T->rchild);
    }
}
void postOrder(BiTree T){
    if (T){
       postOrder(T->lchild);
       postOrder(T->rchild);
       printf("%c,",T->value);
    }
}
int getHeight(BiTree T){
    if (!T){
        return 0;
    }
    int leftHeight = getHeight(T->lchild);
    int rightHeight = getHeight(T->rchild);
    return leftHeight>rightHeight?leftHeight+1:rightHeight+1;
}
//统计每层节点的数量
// void levelCount(BiTree T,int l,int num[]){
//     if (T){
//         num[l]++;
//         levelCount(T->lchild,l+1,num);
//         levelCount(T->rchild,l+1,num);
//     }
// }
int countTNode(BiTree T){
    if (!T){
        return 0;
    }
    int leftCount = countTNode(T->lchild);
    int rightCount = countTNode(T->rchild);
    return leftCount + rightCount + 1;
}
int main(){
    BiTree T;
    T = createTree();
    printf("先序遍历: ");
    preOrder(T);
    printf("\n");
    printf("中序遍历: ");
    inOrder(T);
    printf("\n");
    printf("后序遍历: ");
    postOrder(T);
    printf("\n");
    int height = getHeight(T);
    printf("高度为：%d \n",height);
    cout<<"树的节点数为："<<countTNode(T)<<endl;
    return 0;
}
