class Solution:
    def dfs(self, node, adjls, stack, vis):
        vis[node] = 1
        
        for it in adjls[node]:
            if vis[it] == 0:
                self.dfs(it, adjls, stack, vis)
        
        stack.append(node)
    
    def topoSort(self, V, edges):
        adjls = [[] for _ in range(V)]
        for u,v in edges:
            adjls[u].append(v)
        
        stack = []
        vis = [0] * V
        
        
        ans = []
        for i in range(V):
            if vis[i] == 0:
                self.dfs(i, adjls, stack, vis)
        
        while stack:
            ans.append(stack.pop())
        
        return ans
        