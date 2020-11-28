#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    ll n;
    cin>>n;
    string s;
    vector<char> t;

    cin>>s;
    ll last = n-1;
    for(ll i=0;i<n;i++)
    {
        t.push_back(s[i]);
        last = t.size()-1;
        ll f = 0;
        if(i>=2)
        {
            string match = "fox";
            ll k =2;
            for(ll j=last;j>=j-2;j--,k--)
            {
                if(t[j]!=match[k])
                {
                    f = 1;
                    break;
                }
                last = last-3;
            }
        }
        
    }

}

int main()
{
    string s,t;
    cin>>s;
    cin>>t;

    

    vector<int> ans = rabin_karp(s,t);

    cout<<"size >: "<<ans.size()<<endl;

}