#include <bits/stdc++.h>
using namespace std;


vector<int> adj[100];

int color[100];
int d[100],f[100];
int timex;


void dfs(int source)
{
    int u = source;
    timex++;
    d[u]=timex;
    color[u]=2;
    for(auto v: adj[u])
    {
        if(color[v]==1)
        {
            dfs(v);
        }
    }
    color[u]=3;
    timex++;
    f[u]=timex;
}

void push_node(int x,int v)
{
    adj[x].push_back(v);
    adj[v].push_back(x);
}


void build_graph()
{
    printf("How many edges are there?");
    int f ;cin>>f;

    for(int i=0;i<f;i++)
    {
        int x,v,w;
        cin>>x>>w>>v;
        push_node(x,v);
    }
}

int main()
{
    memset(1,color,sizeof(color));
    memset(0,d,sizeof(d));
    memset(0,f,sizeof(f));
    timex = 0;
    build_graph();
}
