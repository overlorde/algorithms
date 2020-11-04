

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
        return mem[n];    
    }

    mem[n] = fibo(n-1)+fibo(n-2);
    return mem[n];
}

int main()
{
    for(ll i=0;i<10001;i++)v[i].clear();
    mem.clear();
    mem.assign(900+10,-1);
    ll x = fibo(900);

    cout<<x<<endl;
 
}