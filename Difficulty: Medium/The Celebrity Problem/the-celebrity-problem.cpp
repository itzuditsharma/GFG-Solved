//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int top = 0;
        int bottom = n-1;
        
        while(top < bottom){
            if(mat[top][bottom] == 1){
                top++;
            }else if(mat[bottom][top] == 1){
                bottom--;
            }else{
                top++;
                bottom--;
            }
        }
        
        if(top > bottom) return -1;
        
        for(int i = 0; i < n; i++){
            if(i == top) continue;
            if(mat[top][i] == 0 && mat[i][top] == 1) continue;
            else return -1;
        }
        return top;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends