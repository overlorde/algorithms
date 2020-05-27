#include <bits/stdc++.h>
using namespace std;

#define MAX_N 20
#define EMPTY_VALUE -1

int mem[MAX_N];
int next_index[MAX_N];

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
            int subResult = f(j,A);
            if(subResult > ans)
            {
                ans = subResult;
                next_index[i]=j;
            }
        }
    }

    mem[i]=ans + 1;
    return mem[i];
}

vector<int> findLIS(vector<int> A)
{
    int ans = 0;
    for(int i=0;i<A.size();i++)
    {
        mem[i] = EMPTY_VALUE;
        next_index[i] = EMPTY_VALUE;
    }

    int start_index = -1;

    for(int i=0;i<A.size();i++)
    {
        int result = f(i,A);
        if(result > ans)
        {
            ans = result;
            start_index = i;
        }
    }

    vector<int> lis;
    while(start_index != -1)
    {
        lis.push_back(A[start_index]);
        start_index = next_index[start_index];
    }

    return lis;
}

int main()
{
    int n;
    cin>>n;
    vector<int> A;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        A.push_back(x);
    }

    vector<int> path;
    path = findLIS(A);

    for(auto m: path)
    {
        cout<<m<<" ";
    }
    cout<<endl;
}