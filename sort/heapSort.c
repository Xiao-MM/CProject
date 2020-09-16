#include<stdio.h>
void buildHeap(int*, int);
void adjustHeap(int*, int, int);
void swap(int*, int, int);

void heapSort(int arr[],int len){
    buildHeap(arr,len);
    for (int i = len-1; i > 0; i--){
       swap(arr,0,i);
       len--;
       adjustHeap(arr,0,len);
    }
}
void buildHeap(int arr[], int len){
    for(int i = len/2; i>=0; i--){
        adjustHeap(arr,i,len);
    }
}
void adjustHeap(int arr[], int i, int len){
    int left = 2*i+1;
    int right = 2*i+2;
    int max = i;
    if (left<len && arr[left] > arr[max]){
       max = left;
    }
    if (right<len && arr[right] > arr[max]){
       max = right;
    }
    if (i != max){
        swap(arr, i, max);
        adjustHeap(arr, max, len);
    }  
}
void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void printArr(int arr[], int len){
    for (int i = 0; i < len; i++){
        printf("%d ",arr[i]);
    }
    printf("\n"); 
}
int main(){
    int arr[] = {3,1,7,4,2,8,6};
    printArr(arr,7);
    heapSort(arr,7);
    printArr(arr,7);
}


