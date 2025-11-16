import heapq
class Solution:
    # Returns shortest distances from src to all other vertices
    def dijkstra(self, V, edges, src):
        n = V
        adj = [[] for _ in range(n)]
        
        for u,v,w in edges:
            adj[u].append((v,w))
        
        pq = []
        heapq.heappush(pq, (0, src))
        
        dis = [1e9] * n
        dis[src] = 0
        
        while pq:
            dist, node = heapq.heappop(pq)
            
            for adjNode, edw in adj[node]:
                if dis[adjNode] > dis[node] + edw:
                    dis[adjNode] = dis[node] + edw
                    heapq.heappush(pq, (dis[node] + edw, adjNode))
        
        ans = [-1] * n
        for i in range(n):
            if dis[i] != 1e9:
                ans[i] = dis[i]
        
        return ans
                    
        