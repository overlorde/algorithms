#include <bits/stdc++.h>
using namespace std;

#define MAX_N 20
#define EMPTY_VALUE -1

int mem[MAX_N][MAX_N];

int lcs(int i,int j,string &S,string &W)
{
    if(i==S.size() || j==W.size())return 0;

    if(mem[i][j] != EMPTY_VALUE)
    {
        return mem[i][j];
    }
    int ans = 0;
    if(S[i]==W[j])
    {
        ans = 1+lcs(i+1,j+1,S,W);
    }
    else{
        int val1 = lcs(i+1,j,S,W);
        int val2 = lcs(i,j+1,S,W);
        ans = max(val1,val2);
    }
    mem[i][j]=ans;
    return mem[i][j];
}

int main()
{
    for(int i=0;i<MAX_N;i++)
    {
        for(int j=0;j<MAX_N;j++)
        {
            mem[i][j]=-1;
        }
    }

    string s,w;
    cin>>s>>w;


   int ans = lcs(0,0,s,w);

   
}