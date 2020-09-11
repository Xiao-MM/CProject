#include<iostream>
using namespace std;

void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
void print(int arr[],int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void perm(int arr[],int start,int n){
    if (start == n-1){//当只有一个元素的时候退出当前递归
        print(arr,n);
        return;
    }else{
        for (int i = start; i < n; i++){
            swap(arr[i],arr[start]);//子递归体递归结束，需要发生交换让递归继续进行下去
            perm(arr,start+1,n);//对已当start元素搭头的子序列进行递归
            swap(arr[i],arr[start]);//递归完的数据是被改变的，需要将其改回来才能继续
        }
    }
}
int main(){
    int arr[] = {1,2,3};
    perm(arr,0,3);
}
