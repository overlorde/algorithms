#include <bits/stdc++.h>
using namespace std;


int mem[1000][1000];



int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string s,w;
        cin>>s>>w;

        memset(mem,-1,sizeof(mem));

        int ans = lcs(s,w);

        cout<<ans<<endl;
    }
}