# Graph
![image](https://user-images.githubusercontent.com/69719072/169045813-64c2932d-c84b-4727-99c0-82ece458a502.png)

# Undirected Graph
![image](https://user-images.githubusercontent.com/69719072/169046602-0dda5c1c-1cd1-4f56-9312-20453db81cbd.png)
# Directed
- directed graph have 2 degree's in and out degree
- if you sum all indegrees/indegrees you get no of edges
- max no of edges = |V|\*(|V|-1), max is when there is complete graph
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
- we are traversing every edge and total edges are 2xE in undirected graph and E in directed graph
- we are adding an "V + " for a corner case where every node is disconnected
Time Complexity: O(v+e)
### Counting conncted components in an undirected graph
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
void BFSDin(vector<int> adj[], int v) {
  bool visited[v+1];
  int count = 1;
  for(int i=0; i < v; i++)
    visited[i] = false;
  for (int i = 0; i < v; i++)
    if (visited[i] == false) {
      count++;
      visited[i] = true;
      BFS(adj, i, visited);
    }
}
```
