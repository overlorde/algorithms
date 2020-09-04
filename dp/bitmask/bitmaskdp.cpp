#include <bits/stdc++.h>
using namespace std;

#define EMPTY_VALUE -1
#define MAX_N 10
#define INF 999

int w[MAX_N][MAX_N];
int mem[MAX_N][1<<MAX_N];
int n;

int turnOn(int x,int pos)
{
    return x|(1<<pos);
}

bool isOn(int x,int pos)
{
    return (bool)(x&(1<<pos));
}

int f(int i,int mask)
{
    if(mask == (1<<n)-1){
        return w[i][0];
    }

    if(mem[i][mask] != -1)
    {
        return mem[i][mask];
    }

    int ans = INF;

    for(int j=0;j<n;j++)
    {
        if(w[i][j] == INF)continue;

        if(isOn(mask,j)==0)
        {
            int result = f(j,turnOn(mask,j))+w[i][j];
            ans = min(ans,result);
        }
    }

    return mem[i][mask] = ans;
}

int main()
{
    memset(w,INF,sizeof(w));
    memset(mem,-1,sizeof(mem));
   // cout<<w[5][5];
    cin>>n;
    while(1)
    {
        int x,y,v;
        cin>>v;
        if(v==-1)break;
        cin>>x>>y;
        w[x][y]=v;
    }


    int ans =  f(0,0);

    cout<<ans<<endl;

}