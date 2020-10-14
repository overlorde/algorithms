#include <bits/stdc++.h>
using namespace std;

#define MAXX 10000

vector<int> Edges[MAXX],color;


void DFS()
{

}

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int m,n;
        cin>>n>>m;
        color.clear();
        
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