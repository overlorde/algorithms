#include <bits/stdc++.h>
using namespace std;

#define INF 9999
#define EMPTY_VALUE -1

#define MAX_N 20
#define MAX_W 1000

int C[MAX_N];
int mem[MAX_N][MAX_W];

int evaluate_tablet(int i,int W,int n)
{
    if(W<0)return INF;

    if(i == n)
    {
        if(W==0)return 0;
        return INF;
    }
}

int coin_change_iterative(int n,int target)
{
    for(int i=n-1;i>=0;i--)
    {
        for(int w =0;w<=target;i++)
        {
            int rest1 = 1+evaluate_tablet(i+1,w-C[i],n);
            int rest2 = evaluate_tablet(i+1,w,n);
            mem[i][w]=min(rest1,rest2);
        }
    }

    return mem[0][target];
}


