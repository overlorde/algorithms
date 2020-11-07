#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void func()
{
    for(int i=0;i<10;i++)
    {
        v[i]=10;
    }
}

int main()
{
    v.clear();v.assign(100,-1);func();
    for(auto x: v)cout<<x<<endl;
}