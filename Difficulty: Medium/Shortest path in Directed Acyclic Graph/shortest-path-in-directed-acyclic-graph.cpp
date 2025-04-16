//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    void toposort(int node, vector<int> &vis, vector<vector<pair<int, int>>> &adj, stack<int> &st){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            int v = it.first;
            
            if(!vis[v]){
                toposort(v, vis, adj, st);
            }
        }
        
        st.push(node);
    }
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        int n = V;
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        vector<int> vis(n, 0);
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                toposort(i, vis, adj, st);
            }
        }
        
        vector<int> dist(n, 1e9);
        dist[0] = 0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for(auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                
                if(dist[node] + wt < dist[v]){
                    dist[v] = dist[node] + wt;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends