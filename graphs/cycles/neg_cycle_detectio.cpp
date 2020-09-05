#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u,w,v;
};

vector<Edge> E;

int dist[100];

int n;
int neg =0;
void bellman_ford(int s)
{
    for(int i=1;i<=n;i++)
    {
        dist[i]=1000000;
    }
     
    dist[s]=0;
    int flag = 1;
    
    for(int i=1;i<=n;i++)
    {
        for(Edge e: E)
        {
            if(dist[e.v]>dist[e.u]+e.w)
            {
                dist[e.v]=dist[e.u]+e.w;
                if(i==n)
                {
                    neg = 1;
                }
            }
           
        }
        
    }
}
void push_node(int u,int w,int v)
{
    E.push_back({u,w,v});
    E.push_back({v,w,u});
}


void build_graph()
{
    printf("How many edges are there?");
    int f ;cin>>f;

    for(int i=1;i<=f;i++)
    {
        int u,v,w;
        cin>>u>>w>>v;
        push_node(u,w,v);
    }
}

void print_short_distances_from_one()
{

    printf("print list\n");
    for(int i=1;i<=n;i++)
    {

        cout<<dist[i]<<endl;
    }
    if(neg == 1)
    printf("neg cycle : yes\n");
}


int main()
{
    printf("How many nodes ? ");
    cin>>n;
    build_graph();
    bellman_ford(1);
    print_short_distances_from_one();
}