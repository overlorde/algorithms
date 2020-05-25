#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s)
{
    int n = (int)s.length();
    vector<int> pi(n);
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<=i;k++)
        {
            if(s.substr(0,k)==s.substr(i-k+1,k))
                pi[i]=k;
                
        }
    }
    return pi;
}

int main()
{
    vector<int> x;
    string s;
    cin>>s;l

    x=prefix_function(s);
    for(int i  =0;i<x.size();i++)
    {
        cout<<i+1<<": "<<x[i]<<endl;
    }
}