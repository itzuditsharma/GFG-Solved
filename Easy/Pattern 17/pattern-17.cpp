//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        
        for(int i = 0; i < n; i++){
            // Spaces
            for(int j=1; j< n-i ;j++){
                cout<<" ";
            }
            char start = 'A';
            for(int k = 1 ; k <= 2*i+1;k++){
                    cout<<start;
                if(k <= (i*2+1)/2){
                    start++;
                }else{
                    start--;
                }
            }
            cout<<endl;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends