/**
 * @file qs2.cpp
 * @author your name (you@domain.com)
 * @brief 
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

    swap(arr[random],arr[low]);


    return partition(arr,low,high);
}



