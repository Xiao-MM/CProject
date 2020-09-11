#include<stdio.h>
int binarySearch(int arr[],int left,int right,int element){
   
    while (left <= right)
    {
       int mid = (left+right)/2;
       if (element<arr[mid])
          right = mid-1; 
       else if(element>arr[mid])
          left = mid+1;
       else
        return mid;   
    }
    return -1;
}
int main(){
    int arr[] = {1,2,3,4,5,6}; 
    int i = binarySearch(arr,0,5,7);
    printf("%d\n",i);
    return 0;
}