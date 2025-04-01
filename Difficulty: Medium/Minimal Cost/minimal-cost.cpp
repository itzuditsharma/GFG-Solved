//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int f(int ind, int k, vector<int> &arr, vector<int> &dp){
        if(ind == 0) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        int min_cost = INT_MAX;
        
        for(int j = 1; j <=k; j++){
            if(ind - j >= 0){
                int cost = f(ind - j,k, arr, dp) + abs(arr[ind] - arr[ind - j]);
                min_cost = min(min_cost, cost);
            }
        }
        
        return dp[ind] = min_cost;
    }
  
    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n+1, -1);
        return f(n-1, k,arr, dp);
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends