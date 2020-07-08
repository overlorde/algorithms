 articulation_point[] ← false
      visited[] ← false
      low[]=d[u] ← 0
      time ← 0
1     Procedure FindArticulationPoint(G, u):
2     time ←  time+1
3     low[u]=d[u] ← time
4     visited[u] ← true 
5     no_of_children ←  0
6     for each edge u to v in G.adjacentEdges(u) do
7        if(v == parent[u]) continue
8        if visited[v] //This is a backedge
9           low[u] = min(low[u], d[v])
10       end if
11       if not visited[v]   //This is a tree edge
12          parent[u] = v
13          FindArticulationPoint(G, v)
14          low[u] = min(low[u], low[v])
15          if d[u] <= low[v] and u is not root:
16             articulation_point[u]=true
17          end if
18          no_of_children=no_of_children+1
19       end if
20       if(no_of_children>1 u is root):
21            articulation_point[u]=true
22       end if 
23    end for  