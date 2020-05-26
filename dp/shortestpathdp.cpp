#include <bits/stdc++.h>
using namespace std;

#define MAX_N 20
#define INF 99999999
#define EMPTY_LINE -1

int w[MAX_N][MAX_N];
int mem[MAX_N];//memoization array

int f(int u,int n)
{
    if(u==n-1)
    {
        return 0;
    }

    if(mem[u] != EMPTY_LINE)
    {
        return mem[u];
    }

    int ans = INF;

    for(int v = 0;v<n;v++)
    {
        if(w[u][v] != INF)
        {
            ans = min(ans,f(v,n)+w[u][v]);
        }
    }
    mem[u] = ans;
    return mem[u];
}


int main()
{
    
}