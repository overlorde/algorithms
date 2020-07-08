#include <bits/stdc++.h>
using namespace std;



#define MAX_N 20
#define MAX_W 1000

#define INF 9999
#define EMPTY_VALUE -1

int C[MAX_N];
int mem[MAX_W];
int n;

int f_optimized(int W)
{
    if(W<0)return INF;
    if(W==0)return 0;

    if(mem[W] != EMPTY_VALUE)
    {
        return mem[W];
    }

    int ans = INF;

    for(int i=0;i<n;i++)
    {
        ans = min(ans,1+f_optimized(W-C[i]));
    }

    mem[W]=ans;
    return mem[W];
}