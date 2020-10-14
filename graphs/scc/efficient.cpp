#include <bits/stdc++.h>
using namespace std;

#define MAXX 10000
#define GREY -1
#define WHITE -2
vector<int> Edges[MAXX],color,vis;

stack<int> stk;

void DFS(int u)
{
    color[u]=GREY;

    for(auto v : Edges)
    {
        if(color[v]==WHITE)
        {
            DFS(v);
        }
    }

    stk.push(u);
    return;
    
}

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int m,n;
        cin>>n>>m;
        color.clear();vis.clear();

        color.assign(n+1,-2);vis.assign(n+1,0);

        for(int i=0;i<n;i++)
        {
            Edges[i].clear();
        }
        for(int i=0;i<m;i++)
        {

            int u,v;
            cin>>u>>v;  

            Edges[u].push_back(v);
        }

        findSCC();
    }
}