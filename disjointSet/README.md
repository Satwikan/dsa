# Disjoint set

![image](https://i.ibb.co/9w4qhJ8/image-2022-05-29-112814259.png)

- take a friend system if 1 and 2 are friends and 1 is friend with 3 then 3 is friends with 2

## Undirected graph

- we can use a undirected graph to represent this data
- ![image](https://i.ibb.co/3sQV5G3/image-2022-05-29-113424134.png)

## Disjoint set

- we can use a disjoint set to represent this data
- a disjoint can be used to represent different sets in a same universe
- Disjoint means that no two subsets have anythings in common
- ![image](https://i.ibb.co/4jHcsH2/image-2022-05-29-114132897.png)

## Union

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
