#include<iostream>
using namespace std;

void swap(int&,int&);

void selectSort(int arr[],int len){
    int min,k;
    for (int i = 0; i < len; i++){
        min = arr[i];k = i;
        for (int j = i+1; j < len; j++){
            if (arr[j] < min){
                min = arr[j];
                k = j;
            }
        }
        swap(arr[i],arr[k]);
    }
}
void swap(int &a,int &b){
   int temp = a;
   a = b;
   b = temp;
}
void printArr(int arr[],int len){
    for (int i = 0; i < len; i++)
       cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){
    int arr[] = {2,4,1,5,6,9,7};
    printArr(arr,7);
    selectSort(arr,7);
    printArr(arr,7);
}