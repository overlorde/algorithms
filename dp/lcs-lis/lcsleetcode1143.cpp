#include <bits/stdc++.h>
using namespace std;

#define MAX_N 20
#define EMPTY_VAL -1
#define ll long long

ll mem[MAX_N][MAX_N];

ll lcs(ll i,ll j,string &S,string &W)
{
    if(i == (ll)S.size() || j == (ll)W.size())
    {
        return 0;
    }

    ll ans =0;

    if(S[i] == W[j])
    {
        ans = 1+lcs(i+1,j+1,S,W);
    }
    else{
        ans = max(lcs(i+1,j,S,W),lcs(i,j+1,S,W));
    }

    mem[i][j]=ans;
    return mem[i][j];
}


int main()
{
   
}