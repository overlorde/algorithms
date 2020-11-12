#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXD = 200+10, MOD = 10001;
ll x[MAXD];
lla ,k,b,d,c;


void egcd(ll a,ll b,ll &d,ll &x,ll &y)
{
    if(!b)
    {
        d = a;
        x = 1;y = 0;
        return;
    }else{
        egcd(b,a%b,d,y,x);
        y -= x*(a/b);
        return;
    }
}

int main()
{
    int T;
    cin>>T;

    for(int i=1;i<2*T;i+=)
    {
        cin>>x[i];
    }


    for(a = 0;a<MOD;a++)
    {
        c = (x[3]-a*a*x[1]);
    }
}
