//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    
    int f(int i, int capacity, vector<int>& val, vector<int>& wt, vector<vector<int>> &dp){
        // Base cases 4
        
        if(i == 0) {
            int number = int(capacity / wt[i]);
            return number * val[i];
        }
        
        if(dp[i][capacity] != -1) return dp[i][capacity];
        int nottake = f(i-1, capacity, val, wt, dp);
        int take = INT_MIN;
        if(wt[i] <= capacity) take = val[i] + f(i, capacity - wt[i], val, wt, dp);
        return dp[i][capacity] = max(take, nottake);
    }
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
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