#include <bits/stdc++.h>
using namespace std;

//for directed acylic graph

#define MAX_N 20
#define INF 999
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
    int n;
    
    memset(mem,-1,sizeof(mem));
    
    for(int i=0;i<MAX_N;i++)
    {
        for(int j=0;j<MAX_N;j++)
        {
            w[i][j]=INF;
        }
    }
    
    n = 5;
    w[0][1]=2;
    w[0][3]=1;
    w[1][2]=1;
    w[1][4]=9;
    w[3][1]=3;
    w[2][4]=3;

    int res = f(0,n);

    cout<<res<<endl;
   
    

}