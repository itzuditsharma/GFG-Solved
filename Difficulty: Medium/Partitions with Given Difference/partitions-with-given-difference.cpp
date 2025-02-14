//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(int ind, int sum, vector<int>& arr, vector<vector<int>> &dp){
        if(ind == 0){
            if(sum == 0 && arr[0] == 0) return 2;
            if(sum == 0 || sum == arr[0]) return 1;
            return 0;
        }
        
        
        if(dp[ind][sum] != -1) return dp[ind][sum];
        
        int not_take = f(ind - 1, sum, arr, dp);
        int take = 0;
        if(sum >= arr[ind]) take = f(ind - 1, sum - arr[ind], arr, dp);
        
        return dp[ind][sum] = take + not_take;
    }

    int countPartitions(vector<int>& arr, int d) {
        // s1 - s2 = d;
        // totalsum;
        
        // totalsum - s2 -s2 = d;
        // totalsum - d = 2s2
        // s2 = (totalsum - d )/ 2
        int n = arr.size();
        int totalsum = 0;
        for(int i = 0; i < n; i++) totalsum += arr[i];
        if(totalsum - d < 0 || ((totalsum - d) %2 == 1)) return 0;
        int s2 = (totalsum-d)/2;
        vector<vector<int>> dp(n, vector<int>(s2+1, -1));
        return f(n-1, s2, arr, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends