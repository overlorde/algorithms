#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> v;
vector<ll> cycle[101];

ll bigmod(ll a,ll b,ll M)
{
    if(b==0)return 1%M;

    ll x = bigmod(a,b/2,M);

    x = (x*x)%M;

    if(b%2==1) x = (x*a)%M;

    return x;
}

ll fib(ll n)
{
    
    if(n<=1)
    {
        return n;
    }

    if(v[n]!=-1)
    {
        return v[n];
    }

    return v[n]=fib(n-1)+fib(n-2);

}

int main()
{

    v.clear();
    v.assign(101,-1);
    //cout<<v[0];
    
    for(ll i=0;i<=100;i++)
    {
        cycle[i].clear();
        cycle[i].assign(1001,-1);
    }

    ll x = fib(100);
    
    v[1]=0;
    
    cout<<endl;

    for(ll i=1;i<=6;i++)
    {
        for(ll j=1;j<=100;j++)
        cycle[i][j]=v[j]%i;
    }

    for(ll i=1;i<=6;i++)
    {
        cout<<"Cycle : "<<i<<" :"<<endl;

        for(ll j=1;j<=100;j++)
        cout<<cycle[i][j]<<" ";

        cout<<endl;
    }

    cout<<"Main array:"<<endl;
    int count=0;
    for(auto x: v)
    {
        count++;
        cout<<x<<" ";
        if(count>=1)break;
    }
    

    cout<<endl;
}