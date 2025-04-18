//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adj(V);
        int n = adj.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        pq.push({0, src});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        
        while(!pq.empty()){
            int node = pq.top().second;
            int distance = pq.top().first;
            pq.pop();
            
            for(auto it : adj[node]){
                int v = it.first;
                int edw = it.second;
                
                if(dist[v] > distance + edw){
                    dist[v] = distance + edw;
                    pq.push({distance + edw, v});
                }
            }
        }
        vector<int> ans(n, -1);
        for(int i = 0; i < n; i++){
            if(dist[i] != 1e9){
                ans[i] = dist[i];
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(V, edges, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends