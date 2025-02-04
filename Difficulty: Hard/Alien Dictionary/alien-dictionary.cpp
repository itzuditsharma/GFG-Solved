//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> toposort(vector<vector<int>> &adj, int n){
        vector<int> indegree(n);
        for(int i = 0; i < n; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i = 0;i < n; i++){
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
        
        if(topo.size() == n) return topo;
        return {-1};
    }
    
    string findOrder(vector<string> dict, int k) {
        int n = dict.size();
        vector<vector<int>> adj(k);
        
        for(int i = 0; i < n-1; i++){
            string first = dict[i];
            string second = dict[i+1];
            int len = min(first.size(), second.size());
            
            for(int i=0; i < len; i++){
                if(first[i] != second[i]){
                    adj[first[i] - 'a'].push_back(second[i] - 'a');
                    break;
                }
            }
        }
        
        vector<int> topo = toposort(adj, k);
        
        string ans = "";
        
        for(auto it : topo){
            ans += char(it + 'a');  
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            a.push_back(number);
        }
        int K;
        cin >> K;
        getchar();
        Solution obj;
        string ans = obj.findOrder(a, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[a.size()];
        std::copy(a.begin(), a.end(), temp);
        sort(temp, temp + a.size(), f);

        bool f = true;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != temp[i])
                f = false;

        if (f)
            cout << "true";
        else
            cout << "false";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends