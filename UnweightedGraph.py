# Senpai! I am a programme to show how a unweighted graphs works ,I am looking forward to working with you ^^
class graph:
    neighbors = list()

    def check_neighbor(self, n1, n2):
        return n2 in self.neighbors[n1]

    def find_path_bfs(self, n1, n2):
        # this function checks if path exists between n1 and n2
        # using breadth first search and constructs a path if it exists,
        # BFS is very good for finding level of nodes in an unweighted graph
        # BFS uses queue and checks all nodes at same level first,
        # then moves to another level
        # initialization
        visited = [0]*len(self.neighbors)
        parent = [-1]*len(self.neighbors)
        level = [-1]*len(self.neighbors)
        q = list()
        try:
            # start the exploration at n1
            visited[n1] = 1
            parent[n1] = n1
            level[n1] = 1
            q.append(n1)
            # Explore each vertex in q
            while len(q) != 0:
                j = q[0]
                q.remove(q[0])
                for k in self.neighbors[j]:
                    if visited[k] == 0:
                        visited[k] = 1
                        parent[k] = j
                        if level[k] == -1:
                            level[k] = level[j] + 1
                        q.append(k)
        except Exception as e:
            return "Parameters are invalid SENPAI!(//•/ω/•//): " + str(e)
        # construct a path if it exists by looking through node,parent
        if visited[n2] == 1:
            path = [n2]
            j = parent[n2]
            while j != n1:
                path.append(j)
                j = parent[j]
            path.append(n1)
            return "Path: "+str(path[::-1])+" Level: "+str(level[n2])
        else:
            return False

    def find_path_dfs(self, n1, n2):
        # this function checks if path exists between n1 and n2 using depth first search
        # and constructs a path if it exists ,DFS is very good for finding pre and
        # post count which gives info about graph
        # DFS uses stack and checks child node before going through nodes at same level,
        # DFS is more usefull BFS
        # initialization
        visited = [0]*len(self.neighbors)
        parent = [-1]*len(self.neighbors)
        pre, post = [0]*len(self.neighbors), [0]*len(self.neighbors)
        stack = []
        count = 0
        try:
            # start at n1
            visited[n1] = 1
            parent[n1] = n1
            pre[n1] = count
            for j in self.neighbors[n1]:
                stack.append(j)
                count += 1
            while len(stack) != 0:
                i = stack[-1]
                visited[i] = 1
                stack.pop()
                pre[i] = count
                for j in self.neighbors[i]:
                    if visited[j] == 0:
                        visited[j] = 1
                        parent[j] = i
                        stack.append(j)
                        count += 1
                post[i] = count
            post[n1] = count
            return (parent, post[n1])
        except Exception as e:
            return "Parameters are invalid SENPAI!(//•/ω/•//): " + str(e)


# uncomment the following for example
a = graph()
a.neighbors = [[1, 2, 3], [0, 2], [0, 1], [0, 4, 7], [3, 5, 6],
               [4, 6, 7, 8], [4, 5], [3, 5, 8], [5, 7, 9], [8], [11], [10]]

print(a.check_neighbor(0, 1))

print(a.find_path_bfs(0, 9))   # they are connected
print(a.find_path_bfs(2, 11))  # they are not connected
# print(a.find_path_bfs(45, 89))  # these nodes don't exist

print(a.find_path_dfs(0, 9))
