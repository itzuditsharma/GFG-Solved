//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int N) {
        vector<int> primes(N+1);
        for(int i = 0; i < primes.size(); i++){
            primes[i] = i;
        }
        
        for(int i = 2; i*i <=N; i++){
            if(primes[i] == i){
                for(int j = i*i; j<=N; j+=i){
                    primes[j] = i;
                }
            }
        }
        
        vector<int> ans;
        while(N!=1){
            ans.push_back(primes[N]);
            N = N / primes[N];
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends