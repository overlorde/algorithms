#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> adj[101];

void build_graph()
{
    for(ll i=0;i<101;i++)
    {
        adj.clear();
    }
    ll n;m;
    cout<<"Number of Nodes : ";
    cin>>n;
    cout<<"'\n";
    cout<<"Number of edges : ";
    cin>>m;
    cout<<"\n";

    for(ll i=0;i<m;i++)
    {
        ll u,v;

        cin>>u>>v;

        adj[u].push_back(v);adj[v].push_back(u);
    }

}

void init()
{
    vis.clear();
    vis.assign(1001,0);
    
    low.clear();
    low.assign(1001,-1);
    
    d.clear();
    d.assign(1001,-1);

    p.clear();
    p.assign(1001,-1);

}


int main()
{
   
}