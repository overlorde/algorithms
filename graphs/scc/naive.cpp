#include <bits/stdc++.h>
using namespace std;

#define MAXX 100000

int main()
{
    stack<int> stk;

    for(int i=1;i<=10;i++)
    {
        stk.push(i);
    }
    cout<<stk.top()<<endl;
}