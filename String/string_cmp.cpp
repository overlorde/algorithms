#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s)
{
    int n =(int)s.length();
    vector<int> pi(n);
    for(int i=1;i<n;i++)
    {
        int j = pi[i-1];
        while(j>0 && s[i]!=s[j])
        {
            j=pi[j-1];
        }
        if(s[i]==s[j])
        {
            j++;
        }
        pi[i]=j;
    }
    return pi;
}

vector<int> kmp(string s,string t)
{
    string b = s+"#"+t;
    int S = s.size();
    vector<int> v,ans;
    v = prefix_function(b);
    for(int i=S+1;i<v.size();i++)
    {
        if(S==v[i])
        {
            ans.push_back(i-(S+S));
        }
    }
    return ans;
}
int main()
{
    while(1){
    string s,t;
    cin>>s;//>>t;
    vector<int> x;
   // x=kmp(s,t);
    

    x=prefix_function(s);
    for(int i  =0;i<x.size();i++)
    {
        cout<<i+1<<": "<<x[i]<<endl;
    }
}
}