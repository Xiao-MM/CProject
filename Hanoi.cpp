#include<iostream>

using namespace std;

void hanoi(int n,int p1,int p2,int p3)
{
	if(n==1)
		cout<<"盘子从"<<p1<<"移到"<<p3<<endl;
	else
	{
		hanoi(n-1,p1,p3,p2);
		cout<<"盘子从"<<p1<<"移到"<<p3<<endl;
		hanoi(n-1,p2,p1,p3);
	}
}

int main(){
    hanoi(5,1,2,3);
}