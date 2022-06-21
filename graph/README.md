# Graph

![image](https://user-images.githubusercontent.com/69719072/169045813-64c2932d-c84b-4727-99c0-82ece458a502.png)

# Undirected Graph

![image](https://user-images.githubusercontent.com/69719072/169046602-0dda5c1c-1cd1-4f56-9312-20453db81cbd.png)

# Directed

- directed graph has 2 degree's in and out-degree
- if you sum all indegres/indegres you get no edges
- max no of edges = |V|\*(|V|-1), max is when there is a complete graph
- ![image](https://user-images.githubusercontent.com/69719072/169046721-121b83ef-2479-4053-814c-6f8a48fa9496.png)

# Graph Representation

## Adjacency Matrix

- we use adjacency matrix to represent graphs
- undirected graph always form symmetric matrix
- ![image](https://user-images.githubusercontent.com/69719072/169057720-12041da1-f3cc-44fd-a0d8-cad7c3e85d3c.png)
- we can use additional data structure if given vertices are not integers(eg. city's names) like array or dictionary
- ![image](https://user-images.githubusercontent.com/69719072/169058753-cfac7fbf-76c1-4388-8ce0-f75a0a8660af.png)

## Adjacency list

- it only stores which vertices are connected
- saves space and makes operation [finding all adjacent vertex] faster
- we can use dynamic sized array's or linked list as a list
- ![image](https://user-images.githubusercontent.com/69719072/169060145-b90c539e-aa13-4d5b-9bc4-e0d520fb7d0e.png)

### Complexity Analysis

- ![image](https://user-images.githubusercontent.com/69719072/169061965-228a11b2-cb90-41f4-a057-1a8fd3898671.png)

### Implementation

![image](https://user-images.githubusercontent.com/69719072/169511496-bc00b28d-c877-4644-95a0-17c28b261af3.png)

- undirected graph

```
void addEdge(vector<int> adj[], int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}
int main () {
  int v = u;
  vector<int> adj[v];
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 3);
  return 0;
}
```

![image](https://user-images.githubusercontent.com/69719072/169512465-beb1e1d6-a76d-423a-bdaa-bf158decf49b.png)

<hr>

# BFS

## Source is given

- given a undirected graph and a source vertex 's' print bfs
- ![image](https://user-images.githubusercontent.com/69719072/169513126-e3df8f77-d2b3-4848-bcdd-814962022068.png)
- ![image](https://user-images.githubusercontent.com/69719072/169513252-cfe98c45-8959-402c-a2d0-a591d0951b75.png)
- visited means the node have been added to the queue, not printed

```
void bfs(vertex<int> adj[], int v, int s) {
  bool visited[v+1];
  for(int i=0; i < v; i++)
    visited[i] = false;
   queue<int> q;
   q.push(s);
   while(q.empty() == false) {
    int u = q.front();
    q.pop();
    cout << u << " ";
    for (int v: adj[u]) {
      if (!visited[v]) {
        visited[v] = true;
        q.push(v);
      }
    }
   }
}
```

## Source is not given and graph may be disconnected as well

![image](https://user-images.githubusercontent.com/69719072/169516335-f2ba4fbd-5c32-4ed5-8405-99458f87e2bc.png)

```
void bfs(vertex<int> adj[], int v, int s, bool visited[]) {
   queue<int> q;
   q.push(s);
   while(q.empty() == false) {
    int u = q.front();
    q.pop();
    cout << u << " ";
    for (int v: adj[u]) {
      if (!visited[v]) {
        visited[v] = true;
        q.push(v);
      }
    }
   }
}
void BFSDin(vector<int> adj[], int v) {
  bool visited[v+1];
  for(int i=0; i < v; i++)
    visited[i] = false;
  for (int i = 0; i < v; i++)
    if (visited[i] == false) {
      visited[i] = true;
      BFS(adj, i, visited);
    }
}
```

- we are traversing every edge and the total edges are 2xE in the undirected graph and E in a directed graph
- we are adding a "V + " for a corner case where every node is disconnected
  Time Complexity: O(v+e)

### Counting connected components in an undirected graph

- it may be called no of "islands" in a graph

```
void bfs(vertex<int> adj[], int v, int s, bool visited[]) {
   queue<int> q;
   q.push(s);
   while(q.empty() == false) {
    int u = q.front();
    q.pop();
    cout << u << " ";
    for (int v: adj[u]) {
      if (!visited[v]) {
        visited[v] = true;
        q.push(v);
      }
    }
   }
}
int BFSDin(vector<int> adj[], int v) {
  bool visited[v+1];
  int count = 0;
  for(int i=0; i < v; i++)
    visited[i] = false;
  for (int i = 0; i < v; i++)
    if (visited[i] == false) {
      count++;
      visited[i] = true;
      BFS(adj, i, visited);
    }
  return count;
}
```

### Applications of BFS

- Shortest Path in an unweighted Graph
- Web Crawlers in Search Engines
- Peer Peer Networks (BitTorrent)
- Social Networking Search
- In Garbage Collection (Cheney's Algorithm)
- Cycle Detection
- Ford Fulkerson Algorithm
- Broadcasting

<hr/>

# DFS

![image](https://user-images.githubusercontent.com/69719072/169523931-1aab08e1-ce08-44ac-ad58-610a1ced80ec.png)
![image](https://user-images.githubusercontent.com/69719072/169524080-430e886f-2d1b-4284-b37f-0024eb30e750.png)

- it is maily recursive in nature and one graph might have multiple DFS's

```
void DFSRec(vector<int> adj[], int s, bool visited[]) {
  visited[s] = true;
  cout << s << " ";
  for(int u: adj[s])
    if (visited[u] == false)
      DFSRec(adj, u, visited);
}
void DFS(vector<int> adj[], int v, int s) {
  bool visited[v];
  for(int i = 0; i < v; i++)
    visited[i] = false;
   DFSRec(adj, s, visited);
}
```

## Graph is disconnected

![image](https://user-images.githubusercontent.com/69719072/169638994-fda417b5-b85a-4605-9a1e-15e4c7f9a3e1.png)

- count no of connected components as well

```
void DFSRec(vector<int> adj[], int s, bool visited[]) {
  visited[s] = true;
  cout << s << " ";
  for(int u: adj[s])
    if (visited[u] == false)
      DFSRec(adj, u, visited);
}
int DFS(vector<int> adj[], int v) {
  int count = 0;
  bool visited[v];
  for(int i = 0; i < v; i++)
    visited[i] = false;
  for(int i = 0; i < v; i++)
    if (visited[i] == false) {
      count++;
      DFSRec(adj, i, visited);
    }
	return count;
}
```

Time Complexity: O(V + E)

### Applications of BFS

- Cycle Detection
- Topological Sorting
- Strongly Connected components
- Solving Maze and Similar Puzzles
- Path Finding

## Shortest Path in an Unweighted Graph

![image](https://user-images.githubusercontent.com/69719072/169639540-8fda66f8-49e6-4809-98c6-970029574fbf.png)

- <b>use BFS</b>

```
void bfs(vertex<int> adj[], int v, int s) {
bool visited[v+1];
vector<int>dist(n, INFINITY);
dist[s] = 0;
for(int i=0; i < v; i++)
  visited[i] = false;
 queue<int> q;
 q.push(s);
 while(q.empty() == false) {
  int u = q.front();
  q.pop();
  cout << u << " ";
  for (int v1: adj[u]) {
    if (!visited[v1]) {
      visited[v1] = true;
	  dist[v1] = 1 + dist[u];
      q.push(v1);
    }
  }
 }
}
```

## Detect Cycle in an Undirected graph

```
void DFSRec(vector<int> adj[], int s, bool visited[], int parent) {
visited[s] = true;
cout << s << " ";
for(int u: adj[s]){
  if (visited[u] == false)
    if (DFSRec(adj, u, visited, s) == true) return true;
	else if (u != parent) return true;
 }
 return false;
}
bool DFS(vector<int> adj[], int v) {
bool visited[v];
for(int i = 0; i < v; i++)
  visited[i] = false;
for(int i = 0; i < v; i++)
  if (visited[i] == false) {
    if (DFSRec(adj, i, visited, -1) == true) return true;
  }
  return false;
}
```

## Detect Cycle in an directed graph

- solution for undirected graph won't work
- ![image](https://i.ibb.co/kQz04BM/image-2022-05-31-191027667.png)

```
void DFSRec(vector<int> adj[], int s, bool visited[], bool recSt[]) {
visited[s] = true;
recSt[s] = true;
cout << s << " ";
for(int u: adj[s]){
  if ((visited[u] == false && DFSRec(adj, u, visited, recSt))
  || recSt[u]){
  return true;
 recSt[s] = false;
 return false;
}
bool DFS(vector<int> adj[], int v) {
bool visited[v];
bool recSt[v];
for(int i = 0; i < v; i++){
  visited[i] = false;
  recSt[i] = false;
}
for(int i = 0; i < v; i++)
  if (visited[i] == false) {
    if (DFSRec(adj, i, visited, recSt) == true) return true;
  }
}
return false;
```

- Time Complexity: O(V+E)

## Topological Sorting

- input: directed acyclic graph
- output: topological order of the graph
- topological order: vertices are visited in the order of their finishing times
- graph can have multiple topological orders
- ![image](https://i.ibb.co/1Ygkz0P/image-2022-05-31-191730435.png)
- ![image](https://i.ibb.co/8YSRY5b/image-2022-05-31-191826926.png)

### BFS Based Solution (Kahn's Algo)

- store indegrees in every vertex
- create a queue and enqueue all vertices with indegree 0

```
while (!q.empty()) {
  int u = q.front();
  q.pop();
  cout << u << " ";
  for (int v: adj[u]) {
    indegree[v]--;
    if (indegree[v] == 0)
      q.push(v);
  }
}
```

- to get indegree of every vertex we can modify add function of graph
- or we can use a vector<int> indegree(v, 0) and traverse whole adjacency list and increment indegree of every vertex [O(E)]
- Time Complexity: O(V+E)

## Detect Cycle in an directed graph (Kahn's Algo)

- Topological Sort is only for acyclic graph
- thus won't work on this and won't print every vertex
- add a count to check if all vertices are visited

```
int count = 0;
while (!q.empty()) {
  int u = q.front();
  q.pop();
  count++;
  cout << u << " ";
  for (int v: adj[u]) {
    indegree[v]--;
    if (indegree[v] == 0)
      q.push(v);
  }
}
return count != v;
```

- ![image](https://i.ibb.co/gPktxg4/image-2022-05-31-194636870.png)

## Topological Sorting using DFS

- print node only if all dependencies of that node are in the stack and then
- create a empty stack
- for every vertex u, do following

```
if (u is not visited)
  DFS(u, st);
while (st is not empty)
  pop an item from st and print it

DFS(u, st)
 Mask u as visited
 For every adjacent v of u
    if v is not visited
    DFS(v, st)
  push u to st
```

## Minimum Spanning Tree Problem (Prim's Algo)

- greedy algorithm
- given an arrangement of computers as weighted and connected undirected graph.
- ![image](https://i.ibb.co/WVwbw3V/image-2022-06-02-090234687.png)
- Minimize the total wire length and make sure that all computer are connected to each other may be through intermediate computers.
- Prim's algo maintains two sets one in the MST and one not in MST.
- cut the graph between MST set and not MST set
- pick minimum edge from the set of edges that are slashed from graph cutting
- then pick edge with min. weight edge and corresponding vertex to MST set
- ![image](https://i.ibb.co/KqkMx4B/image-2022-06-09-105923626.png)
- ![image](https://i.ibb.co/ZhvgZyf/image-2022-06-09-110132964.png)

### Implementation

- [Reference](https://www.youtube.com/watch?v=eNml2e_dB1w&list=PL0SWhLkCGuU8IwrL9nxGiwQ-3Hy4ijFRh&index=19)
- ![image](https://i.ibb.co/dg2rYrd/image-2022-06-09-110847510.png)
- for set of MST set we maintain boolean array
- for implementing cutting of graph and checking for min edge we maintain a key array which is initialized with infinity
- key array updates with minimum edge distance with
-
- ![image](https://i.ibb.co/1z1Rbn2/image-2022-06-09-114131592.png)

```
int primMST(vector<int> graph[], int V) {
  int key[V], res=0;
  fill(key, key+V, INT_MAX);
  key[0] = 0;
  bool mstSet[v] = false;
  for (int i = 0; i < V; i++) {
    int u = -1;
    for (int i = 0; i < V; i++)
      if (!mstSet[i] && (u == -1 || key[i] < key[u])) u = i;
    mstSet[u] = true;
    res += key[u];
    for (int v = 0; v < V; v++)
      if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
        key[v] = graph[u][v];
  }
  return res;
}
```

```
int minKey(int key[], bool mstSet[]) {
  int min = INT_MAX, min_index;
  for (int v = 0; v < V; v++)
    if (mstSet[v] == false && key[v] < min)
      min = key[v], min_index = v;
  return min_index;
}
void Prims(int v) {
  int parent[v];
  int key[v];
  bool visited[v];
  for (int i = 0; i < v; i++) {
    parent[i] = -1;
    key[i] = INT_MAX;
    visited[i] = false;
  }
  key[0] = 0;
  parent[0] = -1;
  while (true) {
    int u = minKey(key, visited);
    if (u == -1) break;
    visited[u] = true;
    for (int v: adj[u]) {
      if (visited[v] == false && adj[u][v] < key[v]) {
        parent[v] = u;
        key[v] = adj[u][v];
      }
    }
  }
  printMST(parent, v);
}
```

- Time Complexity: O(V^2)
- This can be optimized by using min heap and adjacency list
- Then Time Complexity: O(VlogV) + O((V+E)logV) = O(ElogV)
- for a connected graph V = O(E) because `V-1 <= E < V*(V-1)/2`

## Dijstra's Shortest Path

- given a weighted undirected graph and a source vertex s, find shortest path from s to all other vertices in the graph.
- somewhat like prims's algo
- manage an array 'key' initialized with and pick vertex
- ![image](https://i.ibb.co/Nrx1VVS/image-2022-06-09-134617278.png)

### Facts

- does not work for negative weighted edge
- does the shortest path change if add a fix amount of weight to all edges of the original graph (Yes it does!)
- while multiplying all edges by a constant, the shortest path does not change

### Implementation

- [Reference](https://www.youtube.com/watch?v=9m1uVOt5ySg&list=PL0SWhLkCGuU8IwrL9nxGiwQ-3Hy4ijFRh&index=21)
- Create a min heap and a dist array

```
dist[v] = {infinity, infinity, infinity, ..., infinity};
dist[s] = 0;
insert all disance into pq -> O(V)
while (pq is not empty) {
  pop the min element from pq
  for every adjacent vertex of the popped vertex
    if dist[adjacent] > dist[popped] + weight of edge
      dist[adjacent] = dist[popped] + weight of edge
      push adjacent into pq
}
```

### Code

- ![image](https://i.ibb.co/RPH4kRB/image-2022-06-16-092854014.png)

```
int[] dijkstra(int graph[][], int V, int s) {
  int dist[V];
  for (int i = 0; i < V; i++)
    dist[i] = INT_MAX;
  dist[s] = 0;
  priority_queue<pair<int, int>> pq;
  pq.push({0, s});
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    for (int v = 0; v < V; v++)
      if (graph[u][v] && dist[v] > dist[u] + graph[u][v]) {
        // relax operation
        dist[v] = dist[u] + graph[u][v];
        pq.push({dist[v], v});
      }
  }
  return dist;
}

```

- Time Complexity: O(VlogV + ElogV)

## Kosaraju's Algorithm

- it is used to solve strongly connected components problem in a directed graph
- it is implemented using dfs

### Strongly Connected Components

- strongly connected components are components of graph if all vertices under that component can be reachable to each other
- ![image](https://i.ibb.co/4FG4HZb/image-2022-06-16-094449765.png)
- there is a source component that starts the graph (everything is reachable from source) and sink component that ends the graph
- there can be multiple sink components
- let there be 2 vertices v and u such that v is reachable from u but opposite is not true (u is source, v is sink), then dfs of v should happen before dfs of u

### Algo

![image](https://i.ibb.co/Jzpr5jY/image-2022-06-16-154805153.png)

### Implementation for Step 1

- create an empty stack, st

```
for every vertex u
  if u is not visited
    dfs(u, st)
while st is not empty
  pop the top element from st and add to the result

dfs(u, st)
  mark u as visited
  for every vertex v adjacent to u
    if v is not visited
      dfs(v, st)
  push u into st
```

- Time Complexity: O(V+E)

## Bellman Ford Algorithm

- [Reference](https://www.youtube.com/watch?v=TOcJUEtHSrw&list=PL0SWhLkCGuU8IwrL9nxGiwQ-3Hy4ijFRh&index=26)
- find shortest path from a source vertex to all other vertices in a weighted directed graph
- for a unweighted graph it can be solved using bfs (path with min. number of edges): O(V+E)
- for a directed weighted acyclic graph it can be solved using topological sorting: O(V+E)
- Dijstra's worked with directed/undirected weighted acyclic/cyclic graph but won't work with -ve weighted graph
- Bellman Ford works with -ve weighted graph
- it is a dynamic programming algorithm

### Idea

- first find shortest path that are of one edge length. Then shortest path that are of two edge length and so on.
- relax all edges v-1 times: because for a simple path without loops we would have at most v-1 edges in the path therefore it will guarantee that we generate shortest path
- consider a line graph with following order of relaxing operation
- it would take v-1 time to relax V<sup>n-1</sup> - V<sup>n</sup> edge
- ![image](https://i.ibb.co/1TgJnd0/image-2022-06-16-175651785.png)

```
d[v] = {INT_MAX, INT_MAX, INT_MAX, ..., INT_MAX};
d[s] = 0;
for _ = 0 to V-1
  for every edge (u, v)
    dist[v] = min(dist[v], dist[u] + weight of edge) // relax
```

- ![image](https://i.ibb.co/LhTvBLV/image-2022-06-16-175244342.png)
- O(VE)

### Negative weight Cycle

- we can also detect negative weight cycle using bellman ford algorithm
- for that after relaxing v-1 times, if there is a negative weight cycle, then after relaxing 1 more time we will get a dist for some edge which would be less that we got in out v-1 run.

```
d[v] = {INT_MAX, INT_MAX, INT_MAX, ..., INT_MAX};
d[s] = 0;
for _ = 0 to V-1
  for every edge (u, v)
    dist[v] = min(dist[v], dist[u] + weight of edge) // relax
for every edge (u, v)
    if (d[v] > d[u]+weight(u, 0))
      print "Negative weight cycle"
```

## Articulation Points

- given a connected undirected graph, find all articulation points
- articulation points: these are vertices upon removal of which and their associated edges number of connected components increase more than 1
- ![image](https://i.ibb.co/qDy4CFH/image-2022-06-16-181040900.png)

### Applications

- used to find vulnerable points in a network

### Idea

- we use dfs to find articulation points
- convert the graph as a tree by dfs traversing from a source to every edge, if we find some node has edge to one of the ancestors of the tree then we call it back-edge(dashed edge)
- ![image](https://i.ibb.co/Lx1WmPF/image-2022-06-16-182227834.png)
- now there are 2 rules to find articulation points
- Rule 1: If root of the formed tree has 2 children then the root is articulation point
- Rule 2: if there is non-root node such that it's low value is greater than or equal to the discovery time of that node then the node is articulation point
- Discovery Time: the time when the node is first visited by dfs (counter that starts with 1 increases by 1 for every node discovered)
- Low Value: the lowest discovery time reachable through tree or a back-edge
- then if a node has a child which has low atleast the discovery time of that node, then that child can't reach any of the ancestors upon removal of that node

```
u -> v in DFS Tree
u is articulation point if
  low[v] >= discovery[u]
```

## Bridges in Graph

- similar to articulation points but for edges
- then for

```
u - v
low[v] > disc[u]
```

- ![image](https://i.ibb.co/QChJZrX/image-2022-06-21-083758929.png)

## Tarjan's Algorithm for Strongly Connected Components

- better than kosaraju's algorithm because it only requires only single traversal of the graph

### No cross edge

- it is based on concepts of articulation points and bridges
- while making the tree with back-edge we don't pop the vertices from stack after when their all children are visited like previous instead
- if all adjacent of a vertex u are done with recursive and disc[u] = low[u], then print this vertex and all other vertices in the stack
- ![image](https://i.ibb.co/8Dtx4sF/image-2022-06-21-102808040.png)

### with cross edge

- above we assumed there is no cross edge
- cross edge: two vertices are connected by an edge but not by a back-edge
- ![image](https://i.ibb.co/xDG9LLw/image-2022-06-21-103326829.png)
- if there is a cross edge then on dfs we won't update the low value of the vertex based on cross edge

## Kruskal's Algorithm for Minimum Spanning Tree

- given a weighted connected and undirected graph
- generate a minimum spanning tree for the given graph
- we will just output weight of the produced tree

### Algo
- sort all edges in increasing order
- add 1st edge to the tree
- now for every edge min. to max. until size of mst does not become V-1 check if on adding this edge to our tree it forms cycle if not, then add it edge

### Implementation
- Simple: Create a separate graph for mst and add edges to it, this will require cycle detection algo to run on every edge
- Improve: use Dijoint Set [shown here](https://github.com/Satwikan/dsa/tree/master/disjointSet#kruskals-algorithm)