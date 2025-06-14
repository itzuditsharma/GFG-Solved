class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<int> dis(n, 1e9);
        queue<int> q;
        dis[src] = 0;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto i : adj[node]){
                if(dis[i] > dis[node] + 1){
                    dis[i] = dis[node] + 1;
                    q.push(i);
                }
            }
        }
        
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            if(dis[i] == 1e9){
                ans[i] = -1;
            }else{
                ans[i] = dis[i];
            }
        }
        return ans;
    }
};