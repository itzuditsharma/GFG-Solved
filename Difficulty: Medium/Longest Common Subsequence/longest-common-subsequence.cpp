//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// function to find longest common subsequence

class Solution {
  public:
    int f(int i1, int i2, string &str1, string &str2, vector<vector<int>> &dp){
        if(i1 < 0 || i2 < 0) return 0;
        
        if(dp[i1][i2] != -1) return dp[i1][i2];
        
        if(str1[i1] == str2[i2]){
            return dp[i1][i2] =   1 + f(i1 -1, i2 -1, str1, str2, dp);
        }
        
        return dp[i1][i2] = max(f(i1-1, i2, str1, str2, dp), f(i1, i2 - 1, str1, str2, dp));
    }
    
    int lcs(string& str1, string& str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n, vector<int>(m+1, -1));
        return f(n-1, m-1, str1, str2, dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends