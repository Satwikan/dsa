# Disjoint set

![image](https://i.ibb.co/9w4qhJ8/image-2022-05-29-112814259.png)

- take a friend system if 1 and 2 are friends and 1 is friend with 3 then 3 is friends with 2

## Undirected graph

- we can use a undirected graph to represent this data
## ![image](https://i.ibb.co/3sQV5G3/image-2022-05-29-113424134.png)

## Disjoint set

- we can use a disjoint set to represent this data
- a disjoint can be used to represent different sets in a same universe
- Disjoint means that no two subsets have anythings in common
## ![image](https://i.ibb.co/4jHcsH2/image-2022-05-29-114132897.png)

## Union && Find

![image](https://i.ibb.co/WNXQBTx/image-2022-05-29-114726562.png)
![image](https://i.ibb.co/QCGxMks/image-2022-05-29-124402547.png)

```
int parent[n]
void initialize() {
    for (int i = 0; i < n; i++)
        parent[i] = i;
}
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}
void union(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);
    if (xroot != yroot)
        parent[xroot] = yroot;
}
```

- there is a worst case when tree forms is linear
- to avoid tree to become too case we use Union by Rank

## Union by Rank
## ![image](https://i.ibb.co/7n3qm5C/image-2022-05-30-162650718.png)
- given below example was worst case in simple implementation
## ![image](https://i.ibb.co/sJ8qLHx/image-2022-05-30-163147605.png)
- we will rank to determine node will become child of which node
- rank is nothing but height of binary tree

```
int parent[n], rank[n];
void initialize() {
    for (int i = 0; i < n; i++){
        parent[i] = i;
        rank = 0;
    }
}
int find(int x) {
    if (parent[x] == x) return x;
    return find(parent[x]);
}
void union(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);
    if (xroot == yroot) return;
    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}
```

Time Complexity: Avg = O(logn)

## Path Compression

- it optimizes for future find call
## ![image](https://i.ibb.co/86C81N8/image-2022-05-30-163917415.png)
```
int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}
```

### Time Complexity:

- for m operations on n elements
- Avg O(m \* alpha(n))
- where, alpha(n) is the inverse Ackermann function
- alpha(n) <= 4, for any n

## Kruskal's Algorithm

- to find minimum spanning tree
- a spanning tree is a tree that connects all the vertices in a undirected weighted graph
- Spanning Tree with v vertices has v-1 edges
- minimum spanning tree is a tree that has minimum weight among all the trees

### Input

## ![image](https://i.ibb.co/wzMvzTm/image-2022-05-30-164946281.png)

### Implementation

## ![image](https://i.ibb.co/Km9XtfK/image-2022-05-30-165120570.png)
- simple: create a separate graph for mst
- DS for graph
- graph is represented as array of edges

```
struct Edge {
    int src, dist, weight;
    Edge(int s, int d, int w)
        { src = s; dist = d; weight = w; }
};
// to sort edges by weight
bool myCmp(Edge a, Edge b) {
    return a.weight < b.weight;
}
```
 
- implementation

```
// i: Index of next edge
// E: Total number of edges
// V: Total number of vertices
// s: current size of MST

int parent[v], rank[v];
Edge Output[v-1];
int kruskal(Edge arr[]) {
    sort(arr, arr + e, myCmp);
    for (int i = 0; i < v; i++) { parent[i] = i; rank[i] = 0; }
    int res = 0;
    for (int i = 0, s = 0; s < v-1; i++) {
        Edge e = arr[i];
        int x = find(e.src);
        int y = find(e.dist);
        if (x != y) {
            Output[s] = e;
            s++;
            union(x, y);
            res += e.weight;
        }
    }
    return res;
}
```
## ![image](https://i.ibb.co/MND3y2m/image-2022-05-30-180419424.png)
- Time Complexity: O(ElogE + V + E*aplha(V)) = O(ElogV)
- Auxiliary Space: O(V)