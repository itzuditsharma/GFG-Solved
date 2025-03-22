//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int f(int i, int n, vector<int> &price, vector<vector<int>> &dp){
        if(i == 0){
            return n * price[i];
        }
        
        
        if(dp[i][n] != -1) return dp[i][n];
        
        int nottake = f(i-1, n, price, dp);
        int take = INT_MIN;
        int rodlen = i+1;
        if(rodlen <= n) take = price[i] + f(i, n-rodlen, price, dp);
        
        return dp[i][n] = max(take, nottake);
    }
  
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
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