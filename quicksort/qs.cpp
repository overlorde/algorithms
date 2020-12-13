/**
 * @file qs.cpp
 * @author Farhan Saif (farhansaif488@gmail.com)
 * @brief 
    Quick Sort Algorithm using random pivoting
 * @version 0.1
 * @date 2020-12-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <bits/stdc++>
using namespace std;

#define ll long long
/**
 * @brief 
 * 
 * @param arr 
 * @param low 
 * @param high 
 * @return int 
 */
int partition(int arr[],int low , int high)
{
    int pivot = arr[low];
    int i = low - 1 , j = high + 1;
    while(1)
    {
        while(arr[i]<pivot)
        {
            i++;

        }
    
        while(arr[j]>pivot)
        {
            j--;
        }
        if(i>=j)
        {
            return j;
        }
        swap(arr[p],arr[j]); 

    }

    
}
/**
 * @brief 
 * 
 * @param arr 
 * @param low 
 * @param high 
 * @return int 
 */
int partition_r(int arr[],int low,int high)
{
    srand(time(NULL));
    int random = low + rand() % (high- low);
    swap(arr[random],arr[low]);
    return partition(arr,low , high);
}
/**
 * @brief 
 * 
 * @param arr 
 * @param low 
 * @param high 
 */
void quicksort(int arr[],int low , int high )
{
    if(low < high)
    {
        int pi = partition_r(arr,low,high);
        quicksort(arr,low,pi);
        quicksort(arr,pi+1,high);
    }
}
/**
 * @brief 
 * 
 * @param array 
 * @param n 
 */
void printArray(int array[],int n)
{
    for(int i = 0,i<n,i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}
/**
 * @brief 
 * 
 * @return int 
 */
int main()
{
    int arr[] = {10,7,8,9,1,5};
    int n =  sizeof(arr)/sizof(arr[0]);

    quicksort(arr,0,n-1);
    printf("Sorted Array : \n");0
    printArray(arr,n);

    return 0;
}