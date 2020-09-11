#include<iostream>
#define MaxSize 10
using namespace std;

typedef int ElemType;
typedef struct{
    ElemType data[MaxSize];
    int length;
}SqList;

void InitList(SqList &L){
    for (int i = 0; i < MaxSize; i++){
       L.data[i] = 0;
    }
    L.length = MaxSize;
}
void printList(SqList L){
    for (int i = 0; i < L.length; i++){
        cout<<L.data[i]<<" ";
    }
    cout<<endl;
}
//指定在线性表第i个位置上插入元素e
bool ListInsert(SqList &L,int i,ElemType e){
    if(i<1 || i>L.length+1) return false;
    if(L.length == MaxSize) return false;
    for (int j = L.length-1; j >= i-1; j--){
        L.data[j+1] = L.data[j];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}
//删除线性表第i个元素，并将其值赋给e
bool ListDelete(SqList &L,int i,ElemType &e){
    if (i<1 || i>L.length) return false;
    e = L.data[i-1];
    for (int j = i; j < L.length; j++){
       L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}

//按位查找
ElemType getElem(SqList L, int i){
    if (i<1 || i>L.length) 
        return -1;
    else
        return L.data[i-1];
}
//按值查找
int locateElem(SqList L, ElemType e){
    for (int i = 0; i < L.length; i++){
        if (L.data[i] == e){
            return i+1;
        }
    }
    return -1;
}

int main(){
    SqList L;
    InitList(L);
    int arr[] = {1,2,3,4,5};
    for (int i = 0; i < 5; i++){
        L.data[i] = arr[i];
    }
    L.length = 5;
    printList(L);
    ListInsert(L,1,10);
    printList(L);
    ElemType e;
    ListDelete(L,1,e);
    printList(L);
    int loc1 = getElem(L,3);
    int loc2 = locateElem(L,5);
    cout<<"按位查找："<<loc1<<",按值查找："<<loc2<<endl;
}
