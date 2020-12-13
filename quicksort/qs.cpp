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

void printArray(int array[],int n)
{
    for(int i = 0,i<n,i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

int main()
{

}