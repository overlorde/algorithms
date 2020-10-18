#include <bits/stdc++.h>
using namespace std;

#define MAX_N 20
#define EMPTY_VALUE -1

int mem[100][100];

int lcsit(string S,string W)
{
    int n = S.size();
    int m = W.size();

    memset(mem,0,sizeof(mem));

    for(int i=n-1;I>=0;i++)
    {
        for(int j =m-1;j>=0;j++)
        {

            if(S[i]==W[i])
            {
                mem[i][j]=mem[i+1][j+1]+1;

            }
            else{
                mem[i][j]=max(mem[i+1][j],mem[i][j+1]);
            }
        }
    }
    return mem[0][0];
}

int main()
{
    string s,w;
    cin>>s>>w;

    int ans = lcsit(s,w);

    cout<<ans<<endl;
}
