//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        int n = stations.size();
        vector<int> howMany(n-1, 0);
        priority_queue<pair<double, int>> pq;
        for(int i = 0; i < n-1; i++){
            double diff = stations[i+1] - stations[i];
            pq.push({diff, i});
        }
        
        for(int i = 1; i <= k; i++){
            auto topmost = pq.top();
            pq.pop();
            int index = topmost.second;
            howMany[index]++;
            double new_diff = (stations[index+1] - stations[index])/ (double)(howMany[index] + 1);
            pq.push({new_diff, index});
        }
        
        return pq.top().first + 1e-4;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends