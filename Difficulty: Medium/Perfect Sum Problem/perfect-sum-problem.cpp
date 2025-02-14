//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(int ind, int target, vector<int>& nums,vector<vector<int>> &dp){
        if(ind==0)
        {
            if(target==0 && nums[0]==0) return 2;
            if(nums[0]==target || target==0) return 1;
            return 0;
        }

        if(dp[ind][target] != -1) return dp[ind][target];

        int not_take = f(ind - 1, target, nums,dp);
        int take = 0;
        if(target >= nums[ind]) take = f(ind -1, target - nums[ind], nums, dp);

        return dp[ind][target] = not_take + take;
    }
  
    int perfectSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return f(n-1, target, nums, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends