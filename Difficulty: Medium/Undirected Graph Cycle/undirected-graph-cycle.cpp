//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int> &vis){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, node, adj, vis)==true) return true;
            }else{
                if(it != parent) return true;
            }
            
        }
        return false;
    }
    
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        
        for(int i = 0;i < n; i++){
            if(!vis[i]){
                if(dfs(i, -1, adj, vis) == true) return true;
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