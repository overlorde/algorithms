#include <bits/stdc++.h>
using namespace std;

#define ll long long;

vector<ll> edges[101],d,vis,low,parent;
vector<ll> artuculation_point,count_ap;
ll t;
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