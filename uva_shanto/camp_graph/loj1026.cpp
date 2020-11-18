#include <bits/stdc++.h>
using namespace std;

#define ll long long;

vector<ll> edges[101];

void init()
{
    t = 0;
    
    count_ap.clear();

    bridges.clear();

    articulation_point.clear();
    articulation_point.assign(101,-1);

    vis.clear();
    vis.assign(101,-1);

    
}

int main()
{
    ll t;

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