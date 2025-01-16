//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool detect(int src, vector<vector<int>>& adj, int vis[]){
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push({it, node});
                    vis[it] = 1;
                }else if(it != parent){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        int vis[n];
        for(int i = 0; i < n; i++){
            vis[i] = 0;
        }
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(detect(i, adj, vis) == true){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends