#include <bits/stdc++.h>
using namespace std;

int n,freq[100];

int huffman()
{
    priority_queue<int,vector<int>,greater<int>> PQ;

    for(int i=0;i<n;i++)
    {
        PQ.push(freq[i]);
    }

    while(PQ.size()!=1){
        int a = PQ.top();
        PQ.pop();
        int b = PQ.top();
        PQ.pop();
        PQ.push(a+b);
    }
    return PQ.top();
}

int main()
{
    cin>>n;
    memset(freq,-1,sizeof(freq));
    for(int i=0;i<n;i++)
    {
        cin>>freq[i];
    }
    cout<<huffman();
}