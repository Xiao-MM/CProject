#include<iostream>
#define InitSize 10
using namespace std;

typedef int ElemType;
typedef struct{
    ElemType *data;//指示动态数组的指针
    int MaxSize,length;//定义最大长度和当前线性表长度
}SeqList;

void InitList(SeqList &L){
    L.data = (ElemType*)malloc(InitSize*sizeof(ElemType));
    L.length = 0;
    L.MaxSize = InitSize;
}
//将存储空间扩充len个长度
void IncreaseSize(SeqList &L,int len){
    ElemType *p = L.data;
    L.data = (ElemType*)malloc((L.length+len)*sizeof(ElemType));
    for (int i = 0; i < L.length; i++){
        L.data[i] = p[i];
    }
    L.MaxSize += len;
    free(p);
}

void printList(SeqList L){
    for (int i = 0; i < L.length; i++){
        cout<<L.data[i]<<" ";
    }
    cout<<endl;
}
bool destoryList(SeqList &L){
    if(!L.data) return false;
    free(L.data);
    L.data = NULL;
    L.length = 0;
    L.MaxSize = 0;
    return true;
}
bool ListInsert(SeqList &L, int i, ElemType e){
    if (i<1 || i>L.length+1) return false;
    if (L.length == L.MaxSize) return false;
    for (int j = L.length; j > i-1; j--){
        L.data[j]=L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return true; 
}
bool ListDelete(SeqList &L, int i, ElemType &e){
    if (i<1 || i>L.length) return false;
    e = L.data[i-1];
    for (int j = i; j < L.length; j++){
       L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}
ElemType getElem(SeqList L, int i){
    if (i<1 || i>L.length) 
        return -1;
    else
        return L.data[i-1];
}
int locateElem(SeqList L, ElemType e){
    for (int i = 0; i < L.length; i++){
        if (L.data[i] == e)
            return i+1;
    }
    return -1;
}
void swap(ElemType &a, ElemType &b){
    ElemType temp = a;
    a = b;
    b = temp;
}
void reverse(SeqList &L,int left,int right){
    int sum = left + right;
    int mid = sum/2;
    for (int i = left; i <= mid; i++){
        swap(L.data[i],L.data[sum-i]);                                                                               
    }   
}

int main(){
    SeqList L;
    InitList(L);
    for (int i = 1; i <= 10; i++){
        ListInsert(L,i,i);
    }
    printList(L);
    // ElemType e;
    // ListDelete(L,3,e);
    // cout<<"删除的元素为："<<e<<endl;
    // printList(L);
    // IncreaseSize(L,3);
    // cout<<"扩容后的线性表最大长度为："<<L.MaxSize<<endl;
    // reverse(L);
    // printList(L);
    //reverse(L,0,L.length-1);
    //printList(L);
    reverse(L,0,3);
    reverse(L,4,L.length-1);
    printList(L);
    reverse(L,0,L.length-1);
    printList(L);
}
