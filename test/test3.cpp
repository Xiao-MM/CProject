#include<iostream>
using namespace std;
int A[10];
int main(){
    union
    {
        char str;
        int data;
    };
    data=0x01020304;
    if(str==0x01)
    {
        cout<< "此机器是大端！"<<endl;
    }
    else if(str==0x04){
        cout<<"此机器是小端！"<<endl;
    }
    else{
        cout <<" 暂无法判断此机器类型！"<<endl;
    }
    for (int i = 0; i < 10; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
