class Solution:
    def dfs(self, node, adj, pathVis, vis):
        vis[node] = 1
        pathVis[node] = 1
        
        for it in adj[node]:
            if not vis[it] :
                if self.dfs(it, adj, pathVis, vis) == True:
                    return True
            elif pathVis[it] == 1:
                return True
        
        pathVis[node] = 0
        return False
    
    def isCyclic(self, V, edges):
        pathVis = [0] * V
        vis = [0] * V
        
        adj = [[] for _ in range(V)]
        for u,v in edges:
            adj[u].append(v)
        
        for i in range(V):
            if vis[i] == 0:
                if self.dfs(i, adj, pathVis, vis) == True:
                    return True
        
        return False