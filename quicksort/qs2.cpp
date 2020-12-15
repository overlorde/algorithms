/**
 * @file qs2.cpp
 * @author your name (you@domain.com)
 * @brief 
    here we call part_r to randomly find the pivot and we sort on basis of it
 * @version 0.1
 * @date 2020-12-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */

 #include <bits/stdc++.h>

 using namespace std;
/**
 * @brief 
 * basic partitioning and sort the sub array 
 * @param arr 
 * @param low 
 * @param high 
 * @return int 
 */
 int partition(int arr[],int low , int high)
 {
     int pivot = arr[low];
     // the reason we taking low as pivot is because 
     //in hoare partitioning system low is the way .
     //in part_L we see the rand-th element is exchanged with low and pivot
     //with low
     int i = low -1;
     int j =  high+1;

    while(1)
    {
        while(arr[i]<pivot)
        {
            i++;
        }
        while(arr[i]>pivot)
        {
            j--;
        }
        if(i>=j)
        {
            return j;
        }
        swap(arr[i],arr[j]);
    }
 }

/**
 * @brief rand j selection cause this j desc from high and j will be used as
        pi in quicksort to randomly find the value in mid scale
 *      swaps pivot with end element .
        Hoare low element 
 * @param arr 
 * @param low 
 * @param high 
 * @return int 
 */
int partition_r(int arr[],int low , int high)
{
    srand(time(NULL));
    int random = low + rand()%(high-low);

    swap(arr[random],arr[low]);//we want pivot to become the lowest element 


    return partition(arr,low,high);
}

/**
 * @brief 
 * recursive function to sort 
    it finds pi from partition-r and then uses this to finds the pivot sorts it by swapping 
 * @param arr 
 * @param low 
 * @param high 
 */

void quickSort(int arr[],int low,int high)
{
    //debug
    cout<<"d";
    if(low < high)
    {
        int pi = partition_r(arr,low , high);
        quickSort(arr,low,pi);
        quickSort(arr,pi+1,high);
    }
}

void printArray(int arr[],int n)
{
    for(int i = 0;i < n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

int main()
{
    int arr[] = {15,14,13,12,11,10,9,8,7,6,5,1};

    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr,0,n-1);
    cout<<"sorted array ";

    printArray(arr,n);
}