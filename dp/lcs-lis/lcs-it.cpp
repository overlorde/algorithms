#include <bits/stdc++.h>
using namespace std;

#define MAX_N 20
#define EMPTY_VALUE -1
int mem[MAX_N][MAX_N];
int lcsit(string S,string W)
{
    int n = S.size();
    int m = W.size();

    for(int i=0;i<n;i++)mem[i][m]=0;
    for(int j=0;j<m;j++)mem[n][j]=0;

    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(S[i]==W[j])
            {
                mem[i][j]=mem[i+1][j+1]+1;
            }else{
                mem[i][j]=max(mem[i+1][j],mem[i][j+1]);
            }
        }
    }
    return mem[0][0];
}

int main()
{
    memset(mem,-1,sizeof(mem));
    string s,w;
    cin>>s>>w;

    int ans = lcsit(s,w);

    cout<<ans<<endl;

}