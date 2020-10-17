#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

int n=0,t=0;
int mem[MAXN][MAXN];


struct Matrix{
    int row;
    int col;

    Matrix(int _row,int _col)
    {
        row = _row;
        col = _col;
    }
};

vector<Matrix> mats;


int main()
{
    cin>>t;

    while(t--)
    {
        

        mats.clear();

        memset(mem,-1,sizeof(mem));

        cout<<mem[5][5]<<endl;

    }
}
