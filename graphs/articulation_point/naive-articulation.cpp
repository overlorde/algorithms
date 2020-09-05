#include <bits/stdc++.h>
using namespace std;


vector<int> adj[100];

int color[100];
int d[100],f[100];
int timex=0,num;


void dfs(int source)
{
    int u = source;
    timex++;
    d[u]=timex;
    color[u]=2;
    for(auto v: adj[u])
    {
        if(color[v]==1)
        {
            dfs(v);
        }
    }
    color[u]=3;
    timex++;
    f[u]=timex;
}

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
void removenode(int u)
{
    color[u]=3;
}
void addnode(int u)
{
    color[u]=1;
}

int get_number_of_components()
{
   
    for(int i=0;i<100;i++)
    {
        d[i]=0;
        f[i]=0;
    }
    int xc=0;
      cout<<"q"<<endl;
    for(int i=1;i<=num;i++)
    {
        cout<<color[i]<<endl;
        if(color[i]==1)
        {
            cout<<"insideif"<<endl;
            xc++;
            dfs(i);
        }
    }
    return xc;
}

vector<int> articulationPoint()
{
    vector<int> articulation_points;

    for(int u=1;u<=num;u++)
    {
         for(int i=0;i<100;i++)
        {
            color[i]=1;
        }
        removenode(u);
        int m = get_number_of_components();
        if(m>1)
        {
            articulation_points.push_back(u);
        }
        //addnode(u);
    }
    return articulation_points;
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