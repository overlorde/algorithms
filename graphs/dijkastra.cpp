#include <bits/stdc++.h>
using namespace std;

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

vector<Edge> adj[100];
priority_queue<Node> PQ;

int dist[100];

int n=6;


void dijkastra(int s)
{
    for(int i=0;i<=n;i++)
    {
        dist[i]=10000000;
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
            if(dist[e.v]>e.w+u.cost){
                dist[e.v] = u.cost + e.w; 
                PQ.push(Node(e.v,dist[e.v]));
            }
        }

    }
}

void push_node(int x,int w,int v)
{
    adj[x].push_back({v,w});
    adj[v].push_back({x,w});
}


void build_graph()
{
    printf("How many edges are there?");
    int f ;cin>>f;

    for(int i=0;i<f;i++)
    {
        int x,v,w;
        cin>>x>>w>>v;
        push_node(x,w,v);
    }
}

void print_short_distances_from_one()
{

    printf("print list\n");
    for(int i=1;i<=n;i++)
    {

        cout<<dist[i]<<endl;
    }
}

int main()
{
    build_graph();
    dijkastra(1);
    print_short_distances_from_one();
}