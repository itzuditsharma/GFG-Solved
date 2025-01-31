//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet{
public: 
    vector<int> size, parent;
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int findUPar(int node){
        if(parent[node] == node) return node;
        
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int up_u = findUPar(u);
        int up_v = findUPar(v);
        
        if(up_u == up_v) return;
        
        if(size[up_u] < size[up_v]){
            parent[up_u] = up_v;
            size[up_v] += size[up_u]; 
        }else{
            parent[up_v] = up_u;
            size[up_u] += size[up_v]; 
        }
    }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &grid) {
        int vis[n][m];
        memset(vis, 0, sizeof vis);
        int count = 0;
        vector<int> ans;
        DisjointSet ds(n*m);
        
        
        for(auto it : grid){
            int row = it[0];
            int col = it[1];
            
            if(vis[row][col] == 1){
                ans.push_back(count);
                continue;
            }
            
            vis[row][col] = 1;
            count++;
            
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
            
            for(int i = 0; i < 4; i++){
                int adjRow = row + drow[i];
                int adjCol = col + dcol[i];
                
                if(adjRow >=0 && adjRow < n && adjCol >=0 && adjCol < m){
                    if(vis[adjRow][adjCol] == 1){
                        int nodeNo = row * m + col;
                        int adjNodeNo = adjRow * m + adjCol;
                        
                        if(ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo)){
                            ds.unionBySize(nodeNo, adjNodeNo);
                            count--;
                        }
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends