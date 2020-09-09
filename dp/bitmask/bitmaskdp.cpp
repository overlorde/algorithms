//travelling salesman problem using bitmasking
//author:Farhan Saif

#include <bits/stdc++.h>
using namespace std;


#define inf 10900
#define MAX 100

int w[100][100];
int mem[100][1000];
int n=0;

bool isOn(int num,int pos)
{
    return (bool)(num & (1<<pos));
}
int turnOn(int num,int pos)
{
    return (num | (1<<pos));
}

int f(int i, int mask) {
    if (mask == (1<<n) - 1) {
        return w[i][0];
    }
    
    if (mem[i][mask] != -1) {
        return mem[i][mask];
    }
    
    int ans = inf;
    for (int j = 0;j < n;j++) {
        if (w[i][j] == inf) continue;
        
        if (isOn(mask,j) == 0) {
            int result = f(j, turnOn(mask, j)) + w[i][j];
            ans = min(ans, result);
        }
    }
    
    return mem[i][mask] = ans;
}


int main()
{
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            w[i][j]=inf;
        }
    }

    for(int j=0;j<100;j++)
    {
        for(int i=0;i<100 ;i++)
        {
            mem[j][i]=-1;
        }
    }
   /* cout<<w[3][4]<<endl;
    cout<<mem[4][3]<<endl;
    */

    cin>>n;
    int edges;
    cin>>edges;
    int c=0;
    while(c<edges)
    {
        int i,j;
        cin>>i>>j;
        
        cin>>w[i][j];
        c++;
    }
    cout<<"tested positive 1"<<endl;
    int result = f(0,1);
    cout<<"tested positive 2"<<endl;
    cout<<result;
    
}

