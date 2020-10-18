#include <bits/stdc++.h>
using namespace std;


int mem[1000][1000];


int f(int i,int j,string &s,string &w)
{
    
    if(i==s.size() || j == w.size())
    {
        return 0;
    }
    if(mem[i][j] != -1)
    {
        return mem[i][j];
    }
    int ans =0;

    if(s[i]==w[i])
    {
        ans = 1 + f(i+1,j+1,s,w);
    }else{
        int val1 = f(i+1,j,s,w);
        int val2 = f(i,j+1,s,w);

        ans = max(val1,val2);
    }
    mem[i][j]=ans;
    return mem[i][j];
}



int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string s,w;
        cin>>s>>w;

        //memset(mem,-1,sizeof(mem));
        for(int i=0;i<1000;i++)
        {
            for(int j=0;j<1000;j++)
            {
                mem[i][j]=-1;
            }
        }
        int ans = f(0,0,s,w);

        cout<<ans<<endl;
    }
}
/*
int lcs(int i,int j, string &S, string &W) {   
    if(i == S.size() || j == W.size()) return 0;
    
    if(mem[i][j] != EMPTY_VALUE) {
        return mem[i][j];
    }
    
    int ans=0;
    if(S[i] == W[j]) {
        ans = 1 + lcs(i + 1,j + 1, S, W);
    }
    else{
        int val1 = lcs(i + 1, j, S, W);
        int val2 = lcs(i,j + 1, S, W);
        
        ans=max(val1,val2);
    }
    
    mem[i][j] = ans;
    return mem[i][j];
}*/
