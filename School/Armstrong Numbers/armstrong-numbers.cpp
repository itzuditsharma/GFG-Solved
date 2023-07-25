//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        
        
        int x = n;
        int cube = 0;
        int lastnumber;
        int newnumber = 0;
        
        
        while(n != 0){
            lastnumber = n % 10;
            cube = cube + (lastnumber*lastnumber*lastnumber);
            n = n / 10;
        }
        
        if(cube == x)
            return "Yes";
        else
            return "No";
        
        
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
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends