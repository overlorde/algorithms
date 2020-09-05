#include <bits/stdc++.h>

#define SIZE 5005
#define INT_MAX 2000000000
#define MOD 20071027
#define clr(a) memset(a,0,sizeof(a))
#define reset(a) memset(a,-1,sizeof(a))

int row,m,column;

struct Node
{
    int n;
    int cost;
    Node(){};
    Node(int n,int cost)
    {
        this->n = n;this->cost = cost;
    }
    bool operator<(const Node &node)
    {
        const{return cost>node.cost;}
    }
};

vector<Node> adj[SIZE];
bool visited[SIZE];
int weight[SIZE];
int weight2[SIZE];
int minWeight[SIZE];
bool back[SIZE];


int dijkastra(int start,int end)
{
    priority_queue<Node> q;
    q.push(Node(start,0));
    clr(visited);
    reset(weight);
    reset(weight2);
    clr(back);
    weight[start]=0;
    Node node,temp;

    for(int i=1;i<=n;i++)
    {
        minWeight[i] = INT_MAX;
        for(int j=0;j<adj[i].size();i++)
        {
            minWeight[i]=min(minWeight[i],2*adj[i][j].cost);
        }
    }

    while(!q.empty())
    {
        node = q.top();
        q.pop();

        if(visited[node.n])
        {
            if(weight[node.n]<node.cost && (weight2[node.n]==-1) || weight[node.n] >= node.cost)
            {
                weight2[node.n]=node.cost;
            }
            else continue;
        }
        else visited[node.n] = true;

        for(int i=0;i<adj[node.n]size();i++)
        {
            temp = adj[node.n][i];
            if(weight[temp.n] == -1 || weight[temp.n] > node.cost + temp.cost)
            {
                q.push(Node(temp.n,node.cost+temp.cost));
                weight2[temp.n]=weight[temp.n];
                weight[temp.n]=node.cost + temp.cost;
            }
            else if(weight2[temp.n] == -1 || weight2[temp.n] > node.cost + temp.cost){
                    if(weight[temp.n] != node.cost + temp.cost)
                    {
                        q.push(Node(temp.n,node.cost+temp.cost));
                    }
            }
        
        }
        if(!back[node.n])
        {
            q.push(Node(node.n,weight[node.n]+minWeight[node.n]));
            back[node.n]=true;
        }

    }

    return weight2[end];
}

