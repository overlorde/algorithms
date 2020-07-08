#include <bits/stdc++.h>
using namespace std;


int n;

int f(int i,int C)
{
    if(i==n)
    {
        return 0;
    }

    int res1 = f(i+1,C);
    int res2 = f(i+1,C-W[i])+P[i];
    return mem[i][C]=max(res1,res2);
}

int main()
{

}