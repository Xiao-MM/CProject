#include<iostream>
using namespace std;

void InsertSort(int arr[], int len){
    int key,i,j;
    for (i = 1; i < len; i++){
        if (arr[i] < arr[i-1]){
            key = arr[i];
            for (j = i-1; (j >= 0) && (arr[j] > key ); j--){
                arr[j+1] = arr[j];
            }
            arr[j+1] = key;
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
    InsertSort(arr,7);
    printArr(arr,7);
}