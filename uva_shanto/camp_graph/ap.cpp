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

int main()
{
    
}