//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        
        vector<pair<int, int>> meets;
        for(int i = 0; i < start.size(); i++){
            meets.push_back({end[i], start[i]});
        }
        sort(meets.begin(), meets.end());
        
        int maxend = meets[0].first;
        int meetings = 1;
        
        for(int i = 1; i < meets.size(); i++){
            int st = meets[i].second;
            int en = meets[i].first;
            
            if(st > maxend){
                maxend = en;
                meetings++;
            }
        }
        return meetings;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends