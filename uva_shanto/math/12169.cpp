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
    v.clear();
    v.assign(101,-1);
    for(ll i=0;i<2*n;i+=2)
    {
        ll x;
        cin>>x;
        v[i]=x;
    }
    
    ll T = n*2;
    ll x2 = 0;
    for(ll a = 0;a<10001;a++)
    {
        ll x = 0,y = 0;
        ll g = egcd(a+1,10001,&x,&y);

        for(ll i=1;i<2*T;i+=2)
        {
            x2 = (a*v[i]+x)%10001;
            v[i]=x2;
        }   
    }
}