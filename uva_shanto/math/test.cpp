#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll egcd(ll a,ll b,ll &x,ll &y)
{
  if(a==0)
  {
    x = 0;y= 1;
    return b;

  }

  ll x1,y1;
  ll d = egcd(b%a,a,x1,y1);

  x = y1 - (b/a) * x1;

  y = x1;

  return d;
}



int main()
{
  ll a = 10;
  ll b = 6;

  ll x , y;

  ll g = egcd(a,b,x,y);

  cout<<x<<" "<<y<<" "<<endl;  
}