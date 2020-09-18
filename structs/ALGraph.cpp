#include<iostream>
#include "LinkQueue.cpp"
using namespace std;
#define MAX_VERTEX_NUM 20//最大顶点个数
#define VertexType int//顶点数据类型

typedef struct ArcNode{//邻接表节点
    int adjvex;//邻接点在数组中的下标位置
    struct ArcNode *nextarc;//指向下一个邻接点的指针
}ArcNode;

typedef struct VNode{
    VertexType data;//顶点的数据域
    ArcNode *firstarc;//指向邻接点的指针
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct{
    AdjList vertices;//图中顶点以及各邻接点数组
    int vexnum,arcnum;//顶点数和边数
}ALGraph;
//获取顶点在邻接表数组的下标
int locateVex(ALGraph G,VertexType u){
    for (int i = 0; i < G.vexnum; i++){
        if (G.vertices[i].data == u){
            return i;
        }
    }
    return -1;
}
//创建AOV网，构建邻接表
void CreateAOV(ALGraph *G){
    // G = (ALGraph*)malloc(sizeof(ALGraph));
    cout<<"请输入顶点数：";
    cin>>G->vexnum;
    cout<<endl;
    cout<<"请输入边数：";
    cin>>G->arcnum;//输入顶点数和边数
    cout<<endl<<"请依次输入顶点的值：";
    //循环顶点数，初始化头结点
    for (int i = 0; i < G->vexnum; i++){
        cin>>G->vertices[i].data;
        G->vertices[i].firstarc = NULL;
    }
    cout<<endl<<"请依次输入边：";
    //循环边数，初始化边
    for (int i = 0; i < G->arcnum; i++){
        VertexType u,v;//u - 边的尾节点，v - 边的头结点
        cin>>u>>v;
        ArcNode *p = (ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = locateVex(*G,v);
        p->nextarc = NULL;

        int locate = locateVex(*G,u);
        p->nextarc = G->vertices[locate].firstarc;
        G->vertices[locate].firstarc = p;
    }
    cout<<endl;
}
/*-------------------Stack---------------------*/
/* 0 - 栈空 1 - 栈满*/
typedef struct LNode{
    VertexType value;
    struct LNode *next;
}LNode,*LinkedStack;

void initStack(LinkedStack &S){
    S = (LNode*)malloc(sizeof(LNode));
    S->next = NULL; 
}

bool pop(LinkedStack S,VertexType &value){
    if (!S->next) return '0';
    LinkedStack q = S->next;
    value = q->value;
    S->next = q->next;
    free(q);
    return true;
}
void push(LinkedStack S,VertexType value){
    LinkedStack p = (LinkedStack)malloc(sizeof(LNode));
    p->value = value;
    p->next = S->next;
    S->next = p;
}
//0-栈非空 1-栈空
bool isEmpty(LinkedStack S){
    if (!S->next) 
        return true;
    else 
        return false;  
}
//查找每个节点的入度，节点的出度为链表的长度，入度需要遍历整个图的链表
void FindInDegree(ALGraph G, int indegree[]){
    //初始化入度为0
    for (int i = 0; i < G.vexnum; i++){
        indegree[i] = 0;
    }
    //遍历每个节点的邻接表，将每个包含下标的数组+1
    for (int i = 0; i < G.vexnum; i++){
        ArcNode *p = G.vertices[i].firstarc;
        while (p){
            indegree[p->adjvex]++;
            p = p->nextarc;
        }
    } 
}
void TopologicalSort(ALGraph G){
    LinkedStack S;
    initStack(S);
    int indegree[G.vexnum];
    FindInDegree(G,indegree);
    for (int i = 0; i < G.vexnum; i++){
        if (indegree[i] == 0){
            push(S,i);
        }
    }
    int count = 0;
    while (!isEmpty(S)){
        int index;
        pop(S,index);
        count++;
        int data = G.vertices[index].data;
        cout<<data<<" ";
        for (ArcNode *p = G.vertices[index].firstarc; p; p=p->nextarc){
            if (!(--indegree[p->adjvex]))
                push(S,p->adjvex);
        }
    }
    cout<<endl;
    if (count < G.vexnum){
        cout<<"图中存在环"<<endl;
    }
}

int visit[MAX_VERTEX_NUM];//判断顶点数组中的顶点是否被访问

void DFS(ALGraph G, int v){
    visit[v] = 1;
    cout<<G.vertices[v].data<<" ";
    ArcNode *p = G.vertices[v].firstarc;//定义v节点指向的第一个节点
    while (p){
        if (!visit[p->adjvex]){//如果该节点未被访问，则递归访问其下一个节点
            DFS(G,p->adjvex);
        }
        p = p->nextarc;//否则换条边继续
    }
}
void DFSTraverse(ALGraph G){
    //初始化遍历数组
    for (int i = 0; i < MAX_VERTEX_NUM; i++){
        visit[i] = 0;
    }
    //保证所有顶点都能被遍历到
    for (int i = 0; i < G.vexnum; i++){
        if (!visit[i])
            DFS(G,i);//如果图是连通图，则只会执行一次
    }
}
void BFSTraverse(ALGraph G){
    LinkQueue Q;
    InitQueue(Q);
    //初始化访问数组
    for (int i = 0; i < MAX_VERTEX_NUM; i++){
        visit[i] = 0;
    }
    for (int i = 0; i < G.vexnum; i++){
        if (!visit[i]){
            visit[i] = 1;
            cout<<G.vertices[i].data<<" ";
            EnQueue(Q,i);
            while (!isEmpty(Q)){
                int x;
                DeQueue(Q,x);
                ArcNode *p = G.vertices[x].firstarc;
                while (p){
                    if (!visit[p->adjvex]){
                        visit[p->adjvex] = 1;
                        cout<<G.vertices[p->adjvex].data<<" ";
                        EnQueue(Q,p->adjvex);
                    }
                    p = p->nextarc;
                }
            }        
        }
    }
}
int main(){
    ALGraph *G = (ALGraph*)malloc(sizeof(ALGraph));
    CreateAOV(G);
    TopologicalSort(*G); 
    DFSTraverse(*G);
    cout<<endl;
    BFSTraverse(*G);
    cout<<endl;
}



