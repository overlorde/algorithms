#include <bits/stdc++.h>
using namespace std;

int n,dist[1500];
struct Node{
    int at,cost;

    Node(int _at,int _cost)
    {
        at = _at;
        cost = _cost;
    }
};

bool operator<(Node A,Node B)
{
    return A.cost > B.cost;

}
struct Edge{
    int v,w;
};

vector<Edge> adj[1000];
priority_queue<Node> PQ;


void dijkastra(vector<Edge>adj[],int s)
{
    for(int i=0;i<=n;i++)
    {
        dist[i]=100000000;
    }
    dist[s]=0;
    PQ.push(Node(s,0));

    while(!PQ.empty())
    {
        Node u = PQ.top();
        PQ.pop();

        if(u.cost != dist[u.at])
        {
            continue;
        }
        for(auto e: adj[u.at])
        {
            if(dist[e.v] >e.w + u.cost)
            {
                dist[e.v] = u.cost + e.w;
                PQ.push(Node(e.v,dist[e.v]));
            }
        }
    }
}
void push_node(vector<Edge>adj[],int x,int v,int w)
{
    adj[x].push_back({v,w});
    adj[v].push_back({x,w});
}

void build_graph(vector<Edge>adj[])
{
    cin>>n;
    int f ;cin>>f;

    for(int i=0;i<f;i++)
    {
        int x,v,w;
        cin>>x>>v>>w;
        push_node(adj,x,v,w);
    }
}

int  main()
{
    int t;
    cin>>t;
    int i=1;
    while(t--)
    {
        vector<Edge> adj[1000];
        build_graph(adj);
        
        dijkastra(adj,1);

        if(dist[n]==100000000)
        {
            cout<<"Case "<<i<<": Impossible\n";
        }else{
            cout<<"Case "<<i<<": "<<dist[n]<<endl;
        }
        i++;
    }
}