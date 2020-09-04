#include <bits/stdc+.h>
using namespace std;

#define INF 999
#define EMPTY_VALUE -1

#define MAX_N 20
#define MAX_W 1000

int C[MAX_N];
int mem[MAX_N][MAX_W];
int n;

int f(int i,int W,int C)
{
    if(C==k)
    {
        return 0;
    }
    if(W<0)
    {
        return INF;
    }
    if(n==i)
    {
        if(W==0)
        {
            return 0;
        }
        return INF;
    }

    int res_2 = INF;
     if(C==k){
        res_2 = f(i+1,W,0);
    }

    int res_1 = f(i,W-C[i],C+1);

    mem[i][W]=min(res_1,res_2);

    return mem[i][W];
    
}