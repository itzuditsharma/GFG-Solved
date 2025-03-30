//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
        vector<int> dp(n, 1);
        vector<int> hash(n);
        int maxlen = 0;
        int last_index = 0;
        for(int i = 0; i < n; i++) hash[i] = i;
        
        for(int ind = 0; ind < n; ind++){
            for(int prev = 0; prev < ind; prev++){
                if(nums[prev] < nums[ind] && 1 + dp[prev] > dp[ind]){
                    dp[ind] = 1 + dp[prev];
                    hash[ind] = prev;
                } 
            }
            if(dp[ind] > maxlen){
                maxlen = dp[ind];
                last_index = ind;
            }
        }
        
        vector<int> temp;
        temp.push_back(nums[last_index]);
        while(hash[last_index] != last_index){
            last_index = hash[last_index];
            temp.push_back(nums[last_index]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends