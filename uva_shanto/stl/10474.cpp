

#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

vector<ll> v[1001];

vector<ll> mem;

ll fibo(ll n)
{
    if(n==0 || n==1 || n==2)
    {
        return 1;
    }
    if(mem[n] != -1)
    {
        return mem[u];    
    }

    return mem[n] = fib(n-1)+fib(n-2);
}

int main()
{
    for(ll i=0;i<10001;i++)v[i].clear();
    mem.clear();

    ll x = fibo(900);

    for(ll i=1;i<100;i++)
    {
        for(ll j=1;j<=900;j++)
        {
            v[i].push_back(mem[j]%j);
        }
    }
}