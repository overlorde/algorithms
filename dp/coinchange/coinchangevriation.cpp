#include <bits/stdc++.h>
using namespace std;

#define MAX_N 20
#define MAX_W 10000


#define INF 99999
#define EMPTY_VALUE -1

int C[MAX_N];
int mem[MAX_N][MAX_W];
int n;

int f(int i,int W)
{
    if(W<0)return INF;
    if(n==i)
    {
        if(W==0)return 0;
        return INF;
    }

    if(mem[i][W]==-1)
    {
        return mem[i][W];
    }

    int res_1 = 1+f(i,W-C[i]);
    int res_2 =f(i+1,W);

    mem[i][W]=min(res_1,res_2);
    return mem[i][W];

}


