#include<iostream>
using namespace std;

void ShellSort(int arr[], int len){
    int i, j, dk, key;
    for (int dk = len/2; dk >= 1; dk = dk/2){
        for (i = dk; i < len; i++){
            key = arr[i];
            if (arr[i] < arr[i-dk]){
                for (j = i-dk; j >= 0 && arr[j] > key; j-=dk){
                    arr[j+dk] = arr[j];
                }
                arr[j+dk] = key;
            }
        }
    }
}
void printArr(int arr[],int len){
    for (int i = 0; i < len; i++)
       cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){
    int arr[] = {2,4,1,5,6,9,7};
    printArr(arr,7);
    ShellSort(arr,7);
    printArr(arr,7);
}