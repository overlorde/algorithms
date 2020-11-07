#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> v;
vector<ll> cycle[101];

ll fib(ll n)
{
    if(n <=1 )
    {
        return 0;
    }
    if(n == 2|| n == 3)
    {
        return 1;
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
    v.assign(10001,-1);
    //cout<<v[0];
    
    for(ll i=0;i<=100;i++)
    {
        v[i].clear();
    }

    ll x = fib(10000);
    
    cout<<endl;
}