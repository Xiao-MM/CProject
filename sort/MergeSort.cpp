#include<iostream>
using namespace std;
void Merge(int*,int,int,int);
//分解+合并
void MergeSort(int *arr, int start, int end){
    int mid = (start + end)/2;
    if (start >= end){
        return;
    }
    MergeSort(arr, start, mid);
    MergeSort(arr, mid+1, end);
    Merge(arr,start,mid,end);
}
//归并
void Merge(int *arr,int start,int mid,int end){
    int *temp = (int *)malloc((end-start+1)*sizeof(int));
    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end){
        if (arr[i]<arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++]; 
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= end)
        temp[k++] = arr[j++];
    for (int i = 0; i <= (end - start); i++)
       arr[start + i] = temp[i]; 
    free(temp);
}
void printArr(int arr[],int len){
    for (int i = 0; i < len; i++)
       cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){
    int arr[] = {2,1,4,3,7,5,9,9,6};
    printArr(arr,9);
    MergeSort(arr,0,8);
    printArr(arr,9);
}