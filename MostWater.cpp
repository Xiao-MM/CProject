#include<iostream>
using namespace std;

void getMostWaterInTwoColumns(int A[],int n){
    int i = 0;
    int j = n-1;
    int max = 0;
    int left,right;
    int S;
    while(i < j){
        if (A[i]<A[j])
            S = A[i]*(j-i);
        else
            S = A[j]*(j-i);

        if (max<S){
            max = S;
            left = i;
            right = j;
        }
        if (A[i]<A[j])
            i++;
        else
            j--;
    }
    cout<<"最大面积："<<max<<endl;
    cout<<"柱子号为："<<left<<"-"<<right<<endl;
}
int main(){
    int A[] = {1,3,2,20,36,3,4};
    getMostWaterInTwoColumns(A,7);
}