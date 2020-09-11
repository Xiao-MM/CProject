#include<stdio.h>
void print(int arr[],int len);
int divide(int arr[], int low, int high){
    int key = arr[low];
    while (low < high){
        while (low < high && arr[high] > key) --high;
            arr[low] = arr[high];
        while (low < high && arr[low] < key) ++low;
            arr[high] = arr[low];
    }
    arr[low] = key;
    print(arr,7);
    return low;
}

void quickSort(int arr[], int low, int high){
    int pivot;
    if (low < high){
        pivot = divide(arr, low, high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
}
void print(int arr[],int len){
    for (int i = 0; i < len; i++){
       printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[] = {3,1,2,5,4,7,6};
    int len = sizeof(arr)/sizeof(int);
    print(arr,len);
    quickSort(arr,0,len-1);
    print(arr,len);
}