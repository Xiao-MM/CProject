#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//数据有序
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

LNode* getLastNode(LinkList L){
    LNode *p = L;
    while (p&&p->next){
        p = p->next;
    }
    return p;
}
/*-------------------------------------------------*/
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
void printList(LinkList L){
    LNode *p = L->next;
    while (p){
       cout<<p->data<<" ";
       p = p->next; 
    }
    cout<<endl;
}
int main(){
    LinkList L;
    HeadInsert(L);
    printList(L);
    LNode *a = L->next->next;
    LNode *b = getLastNode(L);
    b->next = a;
    // DeleteSameElem(L);
    // printList(L);
    bool flag = isCircleExist(L);
    cout<<"是否有环："<<flag<<endl;
    int len = calculateCircleLength(L);
    cout<<"环的长度为："<<len<<endl;
    LNode *entry = findEntrance(L);
    if(entry){
        cout<<"入口的数据为："<<entry->data<<endl;
    }
}