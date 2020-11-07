#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> v;


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
    v.assign(100,-1);
    //cout<<v[0];
    
    
    for(ll i=1;i<10;i++)
    {
        cout<<fib(i)<<" ";
    }
    cout<<endl;
}