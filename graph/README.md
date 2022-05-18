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

