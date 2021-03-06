#include <string.h>   
#include <stdio.h>  
 
#define NUMS 12   
#define INF 65535
 
typedef struct  
{   
    char vertex[NUMS];   
    int edges[NUMS][NUMS];   
    int n,e;   
}Graph;   
 
void Dispath(int A[][NUMS],int path[][NUMS],int n); 
 
void ReadGraph(Graph *G)   
{   
	int i,j;
	FILE * fp = fopen("floyd.txt","rw");
	G->n = NUMS;
	G->e = NUMS * NUMS; 
	for(i=0; i<NUMS; i++)
	{
		for(j=0; j<NUMS; j++)
		{
			fscanf(fp,"%d",&(G->edges[i][j]));
			printf("%d \t",G->edges[i][j]);			
		}
		printf("\n");
	}
}   
 
void Floyd(Graph G)
{
	int A[NUMS][NUMS],path[NUMS][NUMS];
	int i,j,k;
	for (i=0;i<G.n;i++)
	{
		for (j=0;j<G.n;j++)
		{
			A[i][j]=G.edges[i][j];
			path[i][j]=-1;
		}
	}
	for (k=0;k<G.n;k++)
	{
		for (i=0;i<G.n;i++)
		{
			for (j=0;j<G.n;j++)
			{
				if (A[i][j]>A[i][k]+A[k][j])
				{
					A[i][j]=A[i][k]+A[k][j];
					path[i][j]=k;
				}
			}
		}
	}
	Dispath(A,path,G.n);
}
//打印i到j之间最短路径经过的节点 
void Ppath(int path[][NUMS],int i,int j)
{
	int k;
	k=path[i][j];
	if (k==-1)
	{
		return;
	}
	Ppath(path,i,k);
	printf("%d,",k + 1);
	Ppath(path,k,j);
}
//打印最短路径和路径 
void Dispath(int A[][NUMS],int path[][NUMS],int n)
{
	int i,j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if (A[i][j]==INF)
			{
				if (i!=j)
				{
					printf("从%d到%d没有路径\n",i+1,j+1);
				}
			}
			else
			{
				printf(" 从%d 到 %d => 最短路径长度为 : %d , 路径站点为 :",i+1,j+1,A[i][j]);
				printf("%d,",i + 1);
				Ppath(path,i,j);
				printf("%d\n",j + 1);
			}
		}
	}
}
 
int main()
{
	Graph G;
	ReadGraph(&G);
	Floyd(G);
	return 0;
}