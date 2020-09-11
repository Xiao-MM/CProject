#include<stdio.h>

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
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

void buildHeap(int arr[], int len){
    for(int i = len/2; i>=0; i--){
        adjustHeap(arr,i,len);
    }
}

void heapSort(int arr[],int len){
    for (int i = len-1; i > 0; i--){
       swap(arr,0,i);
       len--;
       adjustHeap(arr,0,len);
    }
    
}

int main(){
    int arr[] = {3,1,7,4,2,8,6};
    heapSort(arr,7);
    for (int i = 0; i < 7; i++){
        printf("%d",arr[i]);
    }
    
}


