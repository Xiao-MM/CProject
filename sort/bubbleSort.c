#include<stdio.h>
void bubblesort(int arr[],int size){
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
               int temp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = temp;
            }   
        }
    }  
}
int  main(){
    int arr[] = {2,3,1,7,5};
    bubblesort(arr,5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}