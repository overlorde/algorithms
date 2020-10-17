#include <bits/stdc++.h>
using namespace std;


#define MAX_N 100
#define INF 1<<30

int mem[MAX_N][MAX_N];

struct Matrix{
    int row,col;

    
    Matrix(int _row,int _col
    {
        row = _row;
        col = _col;
    }
};

vector<Matrix> mats;

int mergeCost(int i,int j,int k)
{
    return mats[i].roW*mats[k].col*mats[j].col;
}

int f(int i,int j)
{
    if(i >= j)
    {
        return 0;
    }
    if(mem[i][j] != EMPTY_VALUE)
    {
        return mem[i][j];
    }
}


int main()
{
    
}