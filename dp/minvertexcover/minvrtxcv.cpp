#include <bits/stdc++.h>
using namespace std;

#define MAXX 100000

int mem[MAXX][2];
int par[MAXX];
vector<int> edges[MAXX];


int f(int i,int marker)
{
    if(mem[u][marker] != -1)
    {
        return mem[u][marker];
    }

    int ans = marker;
    
}


int main()
{
    memset(mem,-1,sizeof(mem));
    memset(mem,-1,sizeof(par));

    int n;
    cin>>n;

    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;

        edges[u].push_back(v);
        edges[v].push_back(u);

    }

    int ans = 0;
    ans = min(f(0,1),f(0,0));
    cout<<ans<<endl;

    return 0;
}