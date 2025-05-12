//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        int low = 0;
        int n = arr.size();
        int high = n-1;
        int ans = -1;
        
        while(low <= high){
            int mid = (low + high)/2;
            
            if(arr[mid] >= x){
                ans = mid;
                high = mid -1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
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
        string xs;
        getline(cin, xs);
        int x = stoi(xs);
        Solution ob;
        int ans = ob.findCeil(arr, x);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends