#include <bits/stdc++.h>
using namespace std;

#define MAX_N 20
#define EMPTY_VALUE -1

int mem[MAX_N];

int f(int i,vector<int> &A)
{
    if(mem[i] != EMPTY_VALUE)
    {
        return mem[i];
    }

    int ans = 0;

    for(int j=i+1;j<A.size();j++)
    {
        if(A[j]>A[i])
        {
            ans = max(ans,f(j,A));
        }
    }

    mem[i]=ans+1;
    return mem[i];
}

int findLIS(vector<int> A)
{
    int ans =0;
    for(int i=0;i<A.size();i++)
    {
        mem[i]=EMPTY_VALUE;
    }

    for(int i=0;i<A.size();i++)
    {
        ans = max(ans,f(i,A));
    }

    return ans;
}

int main()
{
    int n;
    cout<<"How many numbers u want ?";
    cin>>n;

    vector<int> A;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        A.push_back(x);
    }


    int ans = findLIS(A);   
    cout<<ans;


}