//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        for(int i = 0; i < n; i++){
            // stars 
            
            for(int j = i; j < n; j++){
                cout<<"*";
            }
            
            // spaces
            for(int j = 0; j < 2*i; j++){
                cout<<" ";
            }
            
            // stars
            for(int k = n-i; k > 0; k--){
                cout<<"*";
            }
            
            cout<<endl;
        }
        
        for(int i = 0; i < n; i++){
            // stars
            
            for(int j = 0; j <=i ; j++){
                cout<<"*";
            }
            
            
            // spaces 
            for(int j = 0; j < (2*n)-((i+1)*2);j++){
                cout<<" ";
            }
            
            for(int j = 0; j <=i ; j++){
                cout<<"*";
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