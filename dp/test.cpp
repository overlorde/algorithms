#include <bits/stdc++.h>
using namespace std;


int mem[1000][1000];


int f(int i,int j,string s,string w)
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
        ans = max(f(i+1,j,s,w),f(i,j+1,s,w));
    }

    return mem[i][j]=ans;
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