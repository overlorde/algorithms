void dijkastra(int s)
{
    for(int i=0;i<=n;i++)
    {
        dist[i]=10000000;
    }
    dist[s]=0;
    PQ.push(Node(s,0));

    while(!PQ.empty())
    {
        Node u = PQ.top();
        PQ.pop();

        if(u.cost != dist[u.at])
        {
            continue;
        }

        for(auto e: adj[u.at])
        {
            if(dist[e.v]>e.w+u.cost){
                dist[e.v] = u.cost + e.w; 
                PQ.push(Node(e.v,dist[e.v]));
            }
        }

    }
}