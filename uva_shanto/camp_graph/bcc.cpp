#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> adj[1001],d,vis,low,parent;
vector<ll> articulation_point,count_ap;

vector<pair<ll,ll>> bridges;

ll t;

void build_graph()
{
    for(ll i=0;i<101;i++)
    {
        adj[i].clear();
    }

    ll n,m;
    cout<<"Number of nodes:";
    cin>>n;
    cout
}