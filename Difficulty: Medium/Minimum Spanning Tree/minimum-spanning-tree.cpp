//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSet{
public:
    vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i = 0; i <=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int findUPar(int node){
        if(parent[node] == node) return node;
        
        return parent[node] = findUPar(parent[node]);
    }
    
    void UnionBySize(int u, int v){
        int ul_u = findUPar(u);
        int ul_v = findUPar(v);
        
        if(ul_u == ul_v) return;
        
        if(size[ul_u] < size[ul_v]){
            parent[ul_u] = ul_v;
            size[ul_v] += size[ul_u];
        }else{
            parent[ul_v] = ul_u;
            size[ul_u] += size[ul_v];
        }
    }
};
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<pair<int, pair<int, int>>> edges;
        DisjointSet ds(V);
        
        for(int i = 0; i < V; i++){
            for(auto it : adj[i]){
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                
                edges.push_back({wt, {node, adjNode}});
            }
        }
        
        sort(edges.begin(), edges.end());
        int sum = 0;
        for(auto it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUPar(u) != ds.findUPar(v)){
                sum += wt;
                ds.UnionBySize(u, v);
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends