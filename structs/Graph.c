#define MAX_VERTEX_SIZE 20//最大顶点个数
#define VertextType int//顶点数据的类型
#define InfoType int//图中边的权值类型

/*定义邻接点的数据结构*/
typedef struct ArcNode{
    int adjvex;//邻接点在数组中的下标
    struct ArcNode *nextarc;//邻接点指向的下一个邻接点
    InfoType *info;//信息域
}ArcNode;

/*定义顶点的数据结构*/
typedef struct VNode{
    VertextType data;//顶点的数据
    struct ArcNode *firstarc;//指向的第一个邻接点的指针
}VNode,AdjList[MAX_VERTEX_SIZE];//存储链表各个头结点的数组

/*定义图的结构*/
typedef struct{
    AdjList vertices;//图中顶点的数组
    int vexnum,arcnum;//记录图中顶点数和边数
}ALGraph;


