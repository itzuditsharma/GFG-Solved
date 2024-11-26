//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int i = 0;
        int j = 0;
        int maxlen = 0;
        unordered_map<int, int> mapp;
        while(j < arr.size()){
            mapp[arr[j]]++;
            if(mapp.size() > 2){
                while(mapp.size() > 2){
                    mapp[arr[i]]--;
                    if(mapp[arr[i]] == 0) mapp.erase(arr[i]);
                    i++;
                }
            }
            
            maxlen = max(maxlen, j-i+1);
            j++;
        }
        return maxlen;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalFruits(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends