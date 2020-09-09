//travelling salesman problem using bitmasking
//author:Farhan Saif

#include <bits/stdc++.h>
using namespace std;


#define inf 10900
#define MAX 100

int w[MAX][MAX];
int mem[MAX][1<<MAX];
int n;

bool isTurnOn(int num,int pos)
{
    return num & (1<<pos);
}
int turnOn(int num,int pos)
{
    return num | (1<<pos);
}

int f(int i,int mask)
{
    if(mask == (1<<n)-1)
    {
        return w[i][0];
    }
    if(mem[i][mask] != -1)
    {
        return mem[i][mask];
    }
    int ans = inf;
    for(int j=0;j<n;j++)
    {
        if(w[i][j] == inf)continue;

        if(isTurnOn(j,mask)==0)
        {
            int res = f(j,turnOn(mask,j))+w[i][j];
            ans = min(ans,res);
        }
    }
    return mem[i][mask]=ans;
}


int main()
{
    memset(w,inf,sizeof(w));
    memset(mem,-1,sizeof(mem));

    cin>>n;
    int edges;
    cin>>edges;

    while(edges !=0 )
    {
        int i,j;
        cin>>i>>j;
        int cost;
        cin>>cost;
        w[i][j]=cost;
        edges--;
    }

    int result = f(0,1);

    cout<<result;
}

