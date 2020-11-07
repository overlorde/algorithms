#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> v;
vector<ll> cycle[101];
ll p;

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

    return v[n]=(fib(n-1)+fib(n-2))%p;

}

int main()
{

    v.clear();
    v.assign(109,-1);
    //cout<<v[0];
    
    for(ll i=0;i<=109;i++)
    {
        cycle[i].clear();
        cycle[i].assign(109,-1);
    }
    p=6;
    ll x = (fib(100))%p;
    
    v[1]=1;
    v[0]=0;
    cout<<endl;

    ll ind = 0;
    int c = 0;
    for(ll j=0;j<=100;j++)
    {
        if(v[j]==0 && v[j+1]==1)
        {
            c++;
        }
        if(c>=2)
        {
            ind = j;
            break;        
        }
        cycle[6][j]=v[j];
    }

    for(ll i=0;i<ind;i++)
    {
        cout<<cycle[6][i]<<" ";
    }
    ll a,b;
    cout<<"A B :"<<endl;
    cin>>a>>b;

    cout<<"SIZE"<<endl;

    ll sz = ind-1;

    ll bgmd = bigmod(a,b,sz);

    cout<<bgmd<<endl;
}