#include<stdio.h>
#include<stdlib.h>

typedef struct BiNode{
    char value;
    struct BiNode *left;
    struct BiNode *right;    
}BiNode,*BiTree;

BiTree createTree(){
    char value;
    BiTree T;
    scanf("%c",&value);
    if (value == '#') T = NULL;
    else{
        T = (BiTree)malloc(sizeof(BiNode));
        T->value = value;
        T->left = createTree();
        T->right = createTree();
    }
    return T;
}
void preOrder(BiTree T){
    if (T)
    {
        printf("%c,",T->value);
        preOrder(T->left);
        preOrder(T->right);
    }
}
void inOrder(BiTree T){
    if (T)
    {
        inOrder(T->left);
        printf("%c,",T->value);
        inOrder(T->right);
    }
}
void postOrder(BiTree T){
    if (T)
    {
       postOrder(T->left);
       postOrder(T->right);
       printf("%c,",T->value);
    }
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
    return 0;
}
