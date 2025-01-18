//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    bool dfs(int node, vector<int>&vis, vector<int> pathVis, vector<vector<int>> adj){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, vis, pathVis, adj) == true) return true;
            }else{
                if(pathVis[it] != 0){
                    return true;
                }
            }
        }
        pathVis[it]
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(dfs(i, vis, pathVis, adj) == true) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends