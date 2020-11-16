#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> adj[1001],d,vis,low,parent;
vector<ll> articulation_point,count_ap;

vector<pair<ll,ll> > bridges;

ll t;

void build_grpah()
{
    for(ll i=0;i<101;i++)
    {
        adj[i].clear();
    }
    ll n,m;

    cout<<"Number of Nodes : ";
    cin>>n;
    cout<<"\nNumber of Brtidges : ";
    cin>>m;
    cout<<"\n";

    for(ll i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v]/.push_back(u);
    }

}

void init()
{
    t = 0;
    count_ap.clear();
    bridges.clear();

    articulation_point.clear();
    articulation_point.assign(101,-1);

    vis.clear();
    vis.assign(1001,0);

    low.clear();
    low.assign(1001,0);

    
}

