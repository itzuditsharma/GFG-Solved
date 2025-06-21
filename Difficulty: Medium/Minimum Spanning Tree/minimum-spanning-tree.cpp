class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,0});
        vector<int> vis(V,0);
        
        // {weight, node}
        int sum = 0;
        while(!pq.empty()){
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(vis[node] == 1) continue;
            vis[node] = 1;
            sum += weight;
            
            for(auto it : adj[node]){
                int adjNode = it[0];
                int edw = it[1];
                
                if(!vis[adjNode]){
                    pq.push({edw, adjNode});
                }
                
            }
        }
        
        return sum;
    }
};