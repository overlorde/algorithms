#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];
int edg_id[100];
int vis[100];
int n;
void push_node(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void build_graph()
{
    
    printf("How many nodes?");
    cin>>n;
    while(1)
    {
        int u,v;
        cin>>u;
        if(u==-1)
        {
            break;
        }
        cin>>v;
        push_node(u,v);
    }
}

void dfs(int s)
{
    for(int i=0;i<n;i++)edg_id[i] = vis[i] = 0;

    stack<int> S;
    S.push(s);

    while(!S.empty())
    {
        int u = S.top();
        S.pop();

        while(edg_id[u] < adj[u].size())
        {
            int v = adj[u][edg_id[u]];
            edg_id[u]++;
            if(vis[v]==0)
            {
                vis[v]=1;
                S.push(u);
                S.push(v);
                break;
            }
        }
    }
}


int main()
{
    build_graph();
    dfs(1);
}
