//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int f(int ind, int n, vector<int>&price, vector<vector<int>> &dp){
        if(ind == 0){
            return n * price[0];
        }
        
        
        if(dp[ind][n] != -1) return dp[ind][n];
        
        int notpick = 0 + f(ind -1, n, price, dp);
        int pick = INT_MIN;
        int rod_length = ind + 1;
        if(rod_length <= n) pick = price[ind] + f(ind, n - rod_length, price, dp);
        
        return dp[ind][n] = max(pick, notpick);
    }
  
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(n-1, n, price, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends