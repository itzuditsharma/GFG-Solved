class Solution:
    def dfs(self, node, adj, stack, vis):
        vis[node] = 1
        
        for it in adj[node]:
            if vis[it] == 0:
                self.dfs(it, adj, stack, vis)
        
        stack.append(node)
    
    def topoSort(self, V, edges):
        adj = [[] for _ in range(V)]
        for u, v in edges:
            adj[u].append(v)
        
        vis = [0] * V
        stack = []
        n = len(adj)
        
        for i in range(V):
            if vis[i] == 0:
                self.dfs(i, adj, stack, vis)
        
        ans = []
        while stack:
            ans.append(stack.pop())
            
        return ans
            
            