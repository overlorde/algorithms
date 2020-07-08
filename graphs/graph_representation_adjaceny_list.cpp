#include <bits/stdc++.h>
using namespace std;

//adj list 

const int MX = 1e+9;
const int INF = 1e+9;
typedef struct node Node

Node{
    int id,cost;
    Node(){}
    Node(int _u,int _c)
    {
        u = _u;
        cost = _c;
    }
};

bool operator<(Node A,Node B)
{
    return A.cost > B.cost;
}



vector<vector<Node>> V[MX];

priority_queue<Node> PQ;


void push_node(int u,int v,int w)
{
    V[v].push_back(Node(u,w));
    V[u].push_back({Node(v,w));
}


void build()
{
    int u,v,w;
    while(1)
    {
        if(u == -1)break;
        cin>>u>>v>>w;
        push_node(u,v,w);
    }
}

int cost[100];
int taken[100];

int n;

int prim()
{
    //n = number of nodes
    //INF --big num

    for(int i=0;i<n;i++)
    {
        cost[i]=INF,taken[i]=0;
    }

    int start = 0;

    cost[start]=0;

    PQ.push(Node(start,0));

    int ans  = 0;

    while(!PQ.empty())
    {
        Node x = PQ.top();
        PQ.pop();

        if(taken[x.u])
        {
            continue;
        }
        taken[x.u]=1;
        ans+=x.cost;

        for(auto v: V[x.u])
        {
            if(taken[v.u])continue;

            if(v.cost < cost[v.first])
            {
                PQ.push(Node(v.first,v.second));
                cost[v.u] = v.cost;
            }
        }
    }

    printf("COST OF MST : %d\n",ans);

}

void run_prim()
{
    build();
    prim();
}


int main()
{
    run_prim();
}

