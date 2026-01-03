class Solution:
    def dfs(self, i, parent, adjls, vis):
        vis[i] = 1
        
        for it in adjls[i]:
            if vis[it] == 0:
                if self.dfs(it, i, adjls, vis) == True:
                    return True
            else:
                if it != parent:
                    return True
                    
        return False
    
	def isCycle(self, V, edges):
		vis = [0 for _ in range(V)]
		adjls = [[] for _ in range(V)]
		
		for u,v in edges:
		    adjls[u].append(v)
		    adjls[v].append(u)
		    
		
		for i in range(V):
		    if vis[i] == 0:
		        if self.dfs(i, -1, adjls, vis) == True:
		            return True
		return False
		        
		