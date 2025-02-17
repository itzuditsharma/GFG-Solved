//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int f(int ind, int max_wt, vector<int>& val, vector<int>& wt, vector<vector<int>> &dp){
        
        if(ind == 0){
            int x = int(max_wt / wt[0]);
            return x * val[0];
        }
        
        if(dp[ind][max_wt] != -1) return dp[ind][max_wt];
        
        int notpick = 0 + f(ind - 1, max_wt, val, wt, dp);
        int pick = INT_MIN;
        if(wt[ind] <= max_wt) pick = val[ind] + f(ind, max_wt - wt[ind], val, wt, dp);
        
        return dp[ind][max_wt] = max(pick, notpick);
    }
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
        return f(n-1, capacity, val, wt, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends