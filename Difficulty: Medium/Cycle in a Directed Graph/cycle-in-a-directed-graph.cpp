//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    TOPO Sort KAHN;
    bool isCyclic(int V, vector<vector<int>> adj) {
        int n = adj.size();
        int indegree[n] = {0};
        for(int i = 0;  i < n; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int>q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                
                
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        if(topo.size() == n) return false;
        return true;
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