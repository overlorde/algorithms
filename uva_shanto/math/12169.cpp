#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXD = 200+10, MOD = 10001;
ll x[MAXD];
ll a ,k,b,d,c;


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

    for(int i=1;i<2*T;i+=2)
    {
        cin>>x[i];
    }


    for(a = 0;a<MOD;a++)
    {
        c = (x[3]-a*a*x[1]);
        egcd(1LL*MOD,a+1,d,k,b);

        if(c%d)continue;

        b = b * c / d;

        bool ok = true;

        for(int i=2;i<=2*T;i++)
        {
            if(i&1)
            {
                if(x[i] != ((a*x[i-1]+b)%MOD)){
                    ok = false;break;
                }
            }
            else{
                x[i] = ((a*x[i-1]+b)%MOD);
            }
        }
        if(ok)
        {
            break;
        }
    }

    for(int i=2;i<=2*T;i+=2)
    {
        cout<<x[i]<<endl;
    }
}
