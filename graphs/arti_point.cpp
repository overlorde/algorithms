#include <bits/stdc++.h>
using namespace std;


vector<int> adj[100];

int color[100];
int d[100],f[100];
int timex=0,num;



void push_node(int x,int v)
{
    adj[x].push_back(v);
    adj[v].push_back(x);
}


void build_graph()
{
    printf("How many nodes are there?");
    cin>>num;
    printf("How many edges are there?");
    int f ;cin>>f;

    for(int i=0;i<f;i++)
    {
        int x,v,w;
        cin>>x>>v;
        push_node(x,v);
    }
}

int main()
{
    build_graph();
    vector<int> ans;

    ans = articulationPoint();
    cout<<"ANS:"<<endl;
    for(auto p: ans)
    {
        cout<<p<<" ";
    }
    cout<<endl;
}