#include<stdio.h>
void printArr(int*, int);
void bubblesort(int arr[],int size){
    int flag = 1;
    for (int i = 0; i < size-1; i++){
        flag = 0;
        for (int j = 0; j < size-i-1; j++){
            if (arr[j]>arr[j+1]){
               int temp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = temp;
               flag = 1; 
            }
        }
        if (!flag) return;
        printArr(arr,size); 
    }  
}
void printArr(int arr[], int len){
    for (int i = 0; i < len; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}
int main(){
    int arr[] = {2,3,1,7,5};
    printArr(arr,5);
    bubblesort(arr,5);
    return 0;
}