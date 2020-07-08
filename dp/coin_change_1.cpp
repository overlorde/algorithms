#include <bits/stdc++.h>
using namespace std;

#define MAX_N 20
#define MAX_W 1000

#define INF 999999
#define EMPTY_VALUE -1

int n;
int C[MAX_N];
int mem[MAX_N];

void init()
{
    memset(mem,INF,sizeof(mem));
    memset(C,-1,sizeof(C));
}

int f(int i,int W)
{
    if(W<0)return INF;
    if(i==n){
        if(W==0)
        {
            return 0;
        }
        return INF;
    }

    if(mem[i][W] != EMPTY_VALUE)
    {
        return mem[i][W];
    }

    int res1 = 1+f(i+1,W-C[i]);
    int res2 = f(i+1,W);
    mem[i][W]=min(res1,res2);

    return mem[i][W]; 
}


int main()
{
    init();
    int n ;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>C[i];
    }
}