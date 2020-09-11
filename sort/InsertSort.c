#include<stdio.h>

void insertSort(int arr[],int n){
    //选取第一个元素作为比较对象
    for (int i = 1; i < n; i++)
    {
        //如果待比较元素比前一个元素小，则在有序元素中查找待插入位置
        if (arr[i]<arr[i-1])
        {
            //用j保存待比较元素的前一个元素
            int j = i-1;
            //用x保存当前元素
            int x = arr[i]; 
            //遍历有序列表
            while (j>-1&&x<arr[j])
            {
                //数据后移
                arr[j+1]=arr[j];
                j--;
            }
            //比x小的元素的后一个位置就是待插入的位置
            arr[j+1]=x; 
        }
    }
    
}
int main(){
    int arr[] = {2,1,3,4,8,6};
    insertSort(arr,6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d\n",arr[i]);
    }
    
}