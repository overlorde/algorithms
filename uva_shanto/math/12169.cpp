#include <bits/stdc++.h>
using namespace std;

#define ll long long


vector<ll> v;

ll egcd(ll a,ll b,ll &x,ll &y)
{
    if(a==0)
    {
        x = 0;y = 0;
        return b;
    }
    ll x1,y1;
    ll d = egcd(b%a,a,x1,y1);

    x = y1 - (b/a)*x1;

    y = x1;

    return d;
}

int main()
{
    ll n;
    cin>>n;

    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        v.push_back(x);
    }
}