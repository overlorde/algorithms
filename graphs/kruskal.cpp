#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u,v,w;
};

bool operator<(Edge A,Edge B)
{
    return A.w < B.w;
}

vector<Edge> E;

int p[100];

int find(int x)
{
    if(p[x] == x) return x;

    return p[x]=find(p[x]);
}


void kruskal()
{
    sort(E.begin(),E.end());
    
    int ans = 0;
    int sz = E.size();

    for(int i=0;i<sz;i++)
    {
        
        if(find(E[i].u) != find(E[i].v))
        {
            p[p[E[i].u]] = p[E[i].v];
            ans += E[i].w;
           // printf("ans val every time : %d\n",ans);
        }
    }
    cout<<"ans mst :"<<ans<<endl;
}


void push_node(int u,int w,int v)
{
    E.push_back({u,v,w});
}

void build_graph()
{
    int n ;
    printf("How many edges u want ?");
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int u,w,v;
        cin>>u>>w>>v;
        push_node(u,w,v);
    }
}

int main()
{
    build_graph();
    for(int i=0;i<100;i++)
    {
        p[i]=i;
    }
   
    kruskal();
}