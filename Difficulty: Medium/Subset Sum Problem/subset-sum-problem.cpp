class Solution {
  public:
    bool f(int ind, vector<int>& arr, vector<vector<int>> &dp, int target){
        if(target == 0) return true;
        if(ind == 0) return target == arr[0];
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int notTake = f(ind - 1, arr, dp, target);
        int take = false;
        if(target >= arr[ind]){
            take = f(ind-1, arr, dp, target - arr[ind]);
        }
        
        return dp[ind][target] = take | notTake;
    }
  
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return f(n-1, arr, dp, target);
        
    }
};