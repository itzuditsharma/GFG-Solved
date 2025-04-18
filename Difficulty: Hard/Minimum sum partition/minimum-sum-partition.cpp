//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

  public:
    bool subsetSumK(int i, int target, vector<int>& arr, vector<vector<int>> &dp){
        if(target == 0) return dp[i][target] = true;
        if(i == 0) return dp[i][target] = (target == arr[i]);
        
        if(dp[i][target] != -1) return dp[i][target];
        
        bool nottake = subsetSumK(i-1, target, arr, dp);
        bool take = false;
        if(target >= arr[i]) take = subsetSumK(i-1, target - arr[i], arr, dp);
        
        return dp[i][target] = take | nottake;
    }
  
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
        }
        int target = sum;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        
        for(int tar = 0; tar <= target; tar++){
            subsetSumK(n-1, tar, arr, dp);
        }
        
        int minsum = 1e9;
        for(int s1 = 0; s1 < sum; s1++){
            if(dp[n-1][s1] == true){
                int s2 = sum - s1;
                minsum = min(minsum, abs(s2-s1));
            }
        }
        return minsum;
    }
};



//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int ans = ob.minDifference(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends