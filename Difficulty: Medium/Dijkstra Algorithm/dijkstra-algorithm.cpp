//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int, int>>> adj(V);
        int n = adj.size();
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            a
        }
        vector<int>dist(n, 1e9);
        dist[src] = 0;
        priority_queue<pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int,int>>> pq;
        
        pq.push({0,src}); //Dist, node
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edw = it.second;
                
                if(edw + dis < dist[adjNode]){
                    dist[adjNode] = edw + dis;
                    pq.push({edw+dis, adjNode});
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