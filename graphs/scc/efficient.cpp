#include <bits/stdc++.h>
using namespace std;

#define MAXX 10000
#define GREY -1
#define WHITE -2

vector<int> Edges[MAXX],color,vis,R[MAXX];
vector<int> components[MAXX];

stack<int> stk;
int m=0,n=0;
void reverse()
{
    for(int i=0;i<m;i++)
    {
        for(auto v : edges[i])
        {
            R[v].push_back(i);
        }
    }
}

void DFS(int u)
{
    color[u]=GREY;

    for(auto v : Edges[u])
    {
        if(color[v]==WHITE)
        {
            DFS(v);
        }
    }

    stk.push(u);
    return;

}


void DFS2(int u,int mark)
{
    components[mark].push_back(u);
    vis[u]=1;

    for(auto v : )


}



int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        
        cin>>n>>m;
        color.clear();vis.clear();

        color.assign(n+1,-2);vis.assign(n+1,0);

        for(int i=0;i<n;i++)
        {
            Edges[i].clear();
            components[i].clear();
            R[i].clear();
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