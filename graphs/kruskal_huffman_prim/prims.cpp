#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;

const int INF = 1e+9;

vector<PII> V[100];

struct Node{
    int u,cost;
    Node(){}

    Node(int _u,int _cost)
    {
        u = _u;
        cost = _cost;
    }
};


bool operator<(Node A,Node B)
{
    return A.cost > B.cost;
}

priority_queue<Node> PQ;
int cost[100];
int taken[100];
//n
int n = 6;

void push_node(int u,int v,int w)
{
    V[u].push_back({v,w});
    V[v].push_back({u,w});
}

void build()
{
    int u,v,w,num;

    cout<<"How many edges u want ?"<<endl;
    cin>>num;

    while(num--)
    {
        cin>>u>>v>>w;
        push_node(u,v,w);
    }
}



void prim()
{
    //n=number of nodes
    //INF --big num
    cost[0]=0,taken[0]=0;
    for(int i=1;i<=n;i++)
    {
        cost[i]=INF,taken[i]=0;
    }
    //cout<<"p"<<endl;
    //s is the vertex you want to start the algo

    int s = 1;

    cost[s]=0;

    PQ.push(Node(s,0));

    int ans = 0;


    while(!PQ.empty())
    {
        //cout<<"y"<<endl;
        Node x = PQ.top();
        PQ.pop();

        if(taken[x.u]){
            continue;
        }

        taken[x.u] = 1;

        ans+=x.cost;

        for(PII v :V[x.u])
        {
            //cout<<"x"<<endl;
            if(taken[v.first]) continue;

            if(v.second < cost[v.first])
            {
                PQ.push(Node(v.first,v.second));
                cost[v.first] = v.second;
            }

        }
    }
    cout<<"ans : "<<ans<<endl;
}

int main()
{
    V[0].push_back({0,0});
    build();
    //cout<<"lolmain"<<endl;
    prim();
    cout<<"COST:"<<endl;

    for(int i=0;i<=6;i++)
    {
        cout<<cost[i]<<endl;
    }
}
