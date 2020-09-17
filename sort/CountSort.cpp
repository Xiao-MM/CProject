#include<iostream>
using namespace std;
void printArr(int arr[],int len){
    for (int i = 0; i < len; i++)
       cout<<arr[i]<<" ";
    cout<<endl;
}

void CountSort(int *arr,int *sort,int n){
    int max,min;
    max = min = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] < min){
            min = arr[i];
        }
        if (arr[i] > max){
            max = arr[i];
        }
    }
    int len = max - min + 1;
    int c[len];
    for (int i = min; i <= max; i++){
        c[i] = 0;
    }
    for (int i = 0; i < n; i++){
        c[arr[i]]++;
    }
    for (int i = min+1; i <= max; i++){
        c[i] += c[i-1];
    }
    for (int i = n; i > 0; i--){
        sort[--c[arr[i-1]]] = arr[i-1];
    }
}
int main(){
    int arr[] = {4,3,3,1,5,2,1,7,9,6};
    printArr(arr,10);
    int sort[10];
    CountSort(arr,sort,10);
    printArr(sort,10);
}