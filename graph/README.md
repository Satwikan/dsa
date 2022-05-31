# Graph

![image](https://user-images.githubusercontent.com/69719072/169045813-64c2932d-c84b-4727-99c0-82ece458a502.png)

# Undirected Graph

![image](https://user-images.githubusercontent.com/69719072/169046602-0dda5c1c-1cd1-4f56-9312-20453db81cbd.png)

# Directed

- directed graph has 2 degree's in and out-degree
- if you sum all indegrees/indegrees you get no edges
- max no of edges = |V|\*(|V|-1), max is when there is a complete graph
  ![image](https://user-images.githubusercontent.com/69719072/169046721-121b83ef-2479-4053-814c-6f8a48fa9496.png)

# Graph Representation

## Adjacency Matrix

- we use adjacency matrix to represent graphs
- undirected graph always form symmatrix matrix
  ![image](https://user-images.githubusercontent.com/69719072/169057720-12041da1-f3cc-44fd-a0d8-cad7c3e85d3c.png)
- we can use additional data structre if given vertices are not integers(eg. city's names) like array or dictonary
  ![image](https://user-images.githubusercontent.com/69719072/169058753-cfac7fbf-76c1-4388-8ce0-f75a0a8660af.png)

## Adjacency list

- it only stores which vertices are connected
- saves space and makes operation [findind all adjacent vertix] faster
- we can use dynamic sized array's or linked list as a list
  ![image](https://user-images.githubusercontent.com/69719072/169060145-b90c539e-aa13-4d5b-9bc4-e0d520fb7d0e.png)

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

- count no of cannected components as well

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
- Solving Maze and Similar Puzzels
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
```