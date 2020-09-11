#include<iostream>
#include<stdio.h>
using namespace std;

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

/*---------------------------Basic Method-----------------------------*/
//头插法建立单链表
LinkList HeadInsert(LinkList &L){
    ElemType x;
    LNode *s;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    cin>>x;
    while (x!=99999){
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        cin>>x;
    }
    return L;
}
//尾插法建表
LinkList TailInsert(LinkList &L){
    ElemType x;
    L = (LNode*)malloc(sizeof(LNode));
    LNode *s,*r = L;
    cin>>x;
    while (x!=99999){
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        cin>>x;
    }
    r->next = NULL;
    return L; 
}
//打印链表
void printList(LinkList L){
    LNode *p = L->next;
    while (p){
       cout<<p->data<<" ";
       p = p->next; 
    }
    cout<<endl;
}
//按序号查找元素
LNode* getElem(LinkList L, int i){
    LNode *p = L->next;
    int j = 1;
    if (i == 0) return L;
    if (i < 0) return NULL;
    while (p && j<i){
        p = p->next;
        j++;
    }
    return p;
}
//按值查找
LNode* locateElem(LinkList L,ElemType e){
    LNode *p = L->next;
    while (p){
        if (p->data == e)
            return p;
        p = p->next;    
    }
    return NULL;
}
//在指定位置上插入元素
LinkList Insert(LinkList &L, int i ,ElemType x){
    LNode *p,*s;
    s = (LNode*)malloc(sizeof(LNode)); 
    p = getElem(L,i-1);//获取待插入节点的前一个位置
    s->data = x;
    s->next = p->next;
    p->next = s;
    return L;
}
//删除指定位置的元素
LinkList Delete(LinkList &L, int i,ElemType &x){
    LNode *p,*q;
    p = getElem(L,i-1);
    q = p->next;
    x = q->data;
    p->next = q->next;
    free(q);
    return L;
}
//获取链表最后一个元素的指针
LNode* getLastNode(LinkList L){
    LNode *p = L;
    while (p&&p->next){
        p = p->next;
    }
    return p;
}
/*---------------------------Advanced Method-----------------------------*/
//删除有序链表的重复元素
void DeleteSameElem(LinkList &L){
    LNode *p,*pre,*s;//pre为p指针的前一个指针
    p = L->next;
    pre = L;
    while (p){
        if (p->data != pre->data){
            pre = pre->next;
            p = p->next;
        }else{
            s = p;//防止断链
            pre->next = p->next;
            p = p->next; 
            free(s);
        }
    }
}
//判断链表是否有环
bool isCircleExist(LinkList L){
    LNode *p,*q;
    p = q = L;
    while (p&&q->next){
        p = p->next;
        q = q->next->next;
        if(p == q){
            return true;
        }
    }
    return false;
}
//如果链表有环，则计算环的长度
int calculateCircleLength(LinkList L){
    LNode *p,*q;
    p = q = L;
    int count = 0;
    while (p&&q->next){
        p = p->next;
        q = q->next->next;
        if(p == q){
            break;
        }
    }
    while (p&&q->next){
        count++;
        p = p->next;
        q = q->next->next;
        if(p == q){
            break;
        }
    }
    return count;
}
//如果链表有环，则计算环的入口
LNode* findEntrance(LinkList L){
    LNode *p,*q;
    p = q = L;
    int n = calculateCircleLength(L);
    while (n > 0){
        q = q->next;
        n--;
    }
    while (p&&q){
        p = p->next;
        q = q->next;
        if(p == q){
            return p;
        }
    }
    return NULL;
}
//o(1)时间复杂度删除p指向的元素 (o(1)*(n-1) + o(n))/n = o(1)
void deleteElem(LinkList &L,LNode *p){
    LNode *q;
    if(p->next){//节点不为最后一个节点的时候
        q = p->next;
        p->data = q->data;//将q的元素给p
        p->next = q->next;//p指向q的下一个元素
        free(q);//释放q
        return;
    }
    q = L;
    while (q->next){//节点为最后一个节点，需要遍历链表找到它的前一个节点
        if(q->next == p){
            break;
        }
        q = q->next;  
    }
    q->next = NULL;
    free(p);
}
LNode* findCommonNode(LinkList L1,LinkList L2){
    LNode *p = L1->next,*q = L2->next;
    int len,len1,len2;
    len1 = len2 = 0;
    while (p){
       len1++;
       p = p->next;
    }
    while (q){
        len2++;
        q = q->next;
    }
    //指针回溯
    p = L1->next;
    q = L2->next;
    len = len1 - len2;
    if (len > 0){
        while (len > 0){
            p = p->next;
            len--;
        }
    }else{
        while (len < 0){
            q = q->next;
            len++;
        }
    }
    while (p&&q){
        if(p == q) return p;
        p = p->next;
        q = q->next;
    }
    return NULL;
}
int main(){
    // LinkList L;
    // HeadInsert(L);
    // printList(L);
    // Insert(L,3,7);
    // printList(L);
    // ElemType e;
    // Delete(L,2,e);
    // printList(L);
    // LinkList L2;
    // TailInsert(L2);
    // printList(L2);
    // LNode *p = getElem(L2,0);
    // cout<<p->data<<endl;
    // int *a;
    // cout<<sizeof(a)<<endl;
    LinkList L1;
    TailInsert(L1);
    printList(L1);
    LinkList L2;
    TailInsert(L2);
    printList(L2);
    LNode *r = getLastNode(L2);
    r->next = L1->next->next->next->next;
    LNode *c = findCommonNode(L1,L2);
    cout<<"公共节点的数据为:"<<c->data<<endl;
    //LNode *p = L->next->next;
    // LNode *q = getLastNode(L);
    // deleteElem(L,q);
    // printList(L);
    // LNode *a = L->next->next;
    // LNode *b = getLastNode(L);
    // b->next = a;
    // DeleteSameElem(L);
    // printList(L);
    // bool flag = isCircleExist(L);
    // cout<<"是否有环："<<flag<<endl;
    // int len = calculateCircleLength(L);
    // cout<<"环的长度为："<<len<<endl;
    // LNode *entry = findEntrance(L);
    // if(entry){
    //     cout<<"入口的数据为："<<entry->data<<endl;
    // }
}
