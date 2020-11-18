#include <bits/stdc++.h>
using namespace std;

#define ll long long;

vector<ll> edges[101],d,vis,low,parent;
vector<ll> artuculation_point,count_ap;
ll t;
ll s; // source may change each time i call find arti point functiobn

void init()
{
    t = 0;

    
    
    count_ap.clear();

    bridges.clear();

    articulation_point.clear();
    articulation_point.assign(101,-1);

    vis.clear();
    vis.assign(101,-1);

    low.clear();
    low.assign(101,0);

    d.clear();
    d.assign(101,0);

    parent.clear();
    parent.assign(101,-1);
    
}

void findArticulationPoint(ll u)
{
    t += 1;
    low[u]=d[u]=t;

    vis[u]=1;

    ll no_of_children = 0;

    for(auto v : adj[u])
    {
        if(v == parent[u])
        {
            continue;
        }

        if(vis[v])
        {
            low[u] = min(low[u],d[v]);
        }

        if(!vis[v])
        {
            parent[u] = v;
            findArticulationPoint(v);
            low[u]=min(low[u],low[v]);

            if(d[u]  <= low[v] && u != s)
            {
                if(articulation_point[u] != 1)
                {
                    count_ap.push_back(u);
                }

                articulation_point[u] = 1;
            }
            no_of_children = 1;
        }
    }
}

int main()
{
    cin>>t;

    while(t--)
    {
        for(ll i=0;i<=100;i++)
        {
            edges[i].clear();
        }

        ll n;
        cin>>n;

        for(ll i=0;i<n;i++)
        {
            ll p;
            cin>>p;

            ll q;
            cin>>q;

            for(ll j=0;j<q;j++)
            {
                ll u;
                cin>>u;
                edges[p].push_back(u);
            }
        }

    }
}