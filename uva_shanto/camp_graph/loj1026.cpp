#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> adj[1001],d,vis,low,parent;
vector<ll> articulation_point,count_ap;

//testing vis2 : purpose is to help in finding bridges
vector<ll> vis2;

vector<pair<ll,ll>> bridges;

ll t;
ll n,m,s;
void build_graph()
{
    for(ll i=0;i<101;i++)
    {
        adj[i].clear();
    }
    
    cout<<"Number of Nodes : ";
    cin>>n;
    cout<<"'\n";
    cout<<"Number of edges : ";
    cin>>m;
    cout<<"\n";

    for(ll i=0;i<m;i++)
    {
        ll u,v;

        cin>>u>>v;

        adj[u].push_back(v);adj[v].push_back(u);
    }

}

void init()
{
    t = 0;

    count_ap.clear();

    bridges.clear();

    articulation_point.clear();
    articulation_point.assign(101,-1);

    vis.clear();
    vis.assign(1001,0);

    vis2.clear();
    vis2.assign(1001,0);
    
    low.clear();
    low.assign(1001,0);
    
    d.clear();
    d.assign(1001,0);

    parent.clear();
    parent.assign(1001,-1);
}

void FindArticulationPoint(ll u)
{
    t +=1;
    low[u]=d[u]=t;
    vis[u]=1;
    ll no_of_children = 0;

    for(auto v : adj[u])
    {
        if(v == parent[u]) continue;

        if(vis[v])
        {
            low[u] =  min(low[u],d[v]);
        }

        if(!vis[v])
        {
            parent[u] = v;
            FindArticulationPoint(v);
            low[u] = min(low[u],low[v]);

            if(d[u] < low[v]) //not root find //we are doing it manually,need to find reason
            {
               bridges.push_back({u,v});
               
            }
            no_of_children +=1;
        }
        if(no_of_children > 1  && u == s)
        {
            
            if(articulation_point[u] !=1)
            count_ap.push_back(u);
            
            articulation_point[u] = 1;
           
            cout<<"U2: "<<u<<" V2:"<<v<<endl;
        }
        if(d[u]<low[v])
        {
            bridges.push_back({u,v});
        }
    }
}



int main()
{
    int cnt= 0;
    while(1)
    {
        init();
        build_graph();
        
        
        for(ll i = 0;i<n;i++)
        {
            
            if(vis[i] && adj[i].size() ==1)
            {
                continue;
            }
            s = i;
            
            FindArticulationPoint(i);
            
        }
        
        cnt++;
        cout<<"Test case : "<<cnt<<endl;/**/
        cout<<"Printing Articulation Points:\n";
        for(auto n : count_ap)
        {
            cout<<n<<" ";
        }
        cout<<"\nPrinting Bridges : \n";
        for(auto x : bridges)
        {
            cout<<x.first<<" "<<x.second<<endl;            
        }
        cout<<"\n";/**/
        cout<<"Print d[u] ,low[u]\n";
        for(ll i=0;i<n;i++)
        {
            cout<<"Node : "<<i<<" d[u] : "<<d[i]<<" low[u] : "<<low[i]<<" "<<endl;
        }


    }
}