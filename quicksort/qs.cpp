#include <bits/stdc++>
using namespace std;

#define ll long long

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

int partition_r(int arr[],int low,int high)
{
    srand(time(NULL));
    int random = low + rand() % (high- low);
    swap(arr[random],arr[low]);
    return partition(arr,low , high);
}

void quicksort(int arr[],int low , int high )
{
    if(low < high)
    {
        int pi = partition_r(arr,low,high);
        quicksort(arr,low,pi);
        quicksort(arr,pi+1,high);
    }
}

void printArray(int array[],int n)
{
    for(int i = 0,i<n,i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

int main()
{
    int arr[] = {10,7,8,9,1,5};
    int n =  sizeof(arr)/sizof(arr[0]);

    quicksort(arr,0,n-1);
    printf("Sorted Array : \n");0
    printArray(arr,n);

    return 0;
}