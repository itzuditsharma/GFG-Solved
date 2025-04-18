//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job {
    int id;       // Job Id
    int deadline; // Deadline of job
    int profit;   // Profit if job is over before or on deadline
};


// } Driver Code Ends
/*
struct Job
{
    int id;	 // Job Id
    int deadline; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

static bool comp(const Job &a, const Job &b){
    return a.profit > b.profit;
}

class Solution {
  public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job jobs[], int n) {
        sort(jobs, jobs + n, comp);
        int maxdeadline = jobs[0].deadline;
        for(int i = 1; i < n; i++){
            maxdeadline = max(maxdeadline, jobs[i].deadline);
        }
        
        int hash[maxdeadline + 1];
        for(int i = 0; i <=maxdeadline; i++){
            hash[i] = -1;
        }
        
        int count = 0;
        int jobprofit = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = jobs[i].deadline; j > 0; j--){
                if(hash[j] == -1){
                    hash[j] = jobs[i].deadline;
                    jobprofit += jobs[i].profit;
                    count++;
                    break;
                }
            }
        }
        
        return {count, jobprofit};
        }
    
};

//{ Driver Code Starts.
//    Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;

    while (t--) {
        int n;

        // size of array
        cin >> n;
        Job arr[n];

        // adding id, deadline, profit
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].deadline = y;
            arr[i].profit = z;
        }
        Solution ob;
        // function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends