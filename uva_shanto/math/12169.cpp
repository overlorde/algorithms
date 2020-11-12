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
    v.assign(103,-1);
    for(ll i=1;i<=2*n;i+=2)
    {
        ll x;
        cin>>x;
        v[i]=x;
    }
    
    ll T = n*2;
    ll x3 = 0;
    for(ll a = 0;a<10001;a++)
    {
        ll x = 1,y = 1;
        ll g = egcd(a+1,10001,x,y);

        for(ll i=1;i<=2*n;i+=1)
        {
            if(!i%2)
            {
                 v[i] = (a*v[i-1]+x)%10001;
            }
            else if(i%2){
                x3 = (a*v[i-1]+x)%10001;
                if(x3 != v[i])
                {
                    f = 0;
                    break;
                }
            }
        }
         
    }

    for(ll j = 2;j<=2*n;j+=2)
    {
        cout<<v[j]<<endl;
    }

    return 0;
}