class Solution {
  public:
    int f(int row, int j1, int j2, int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp){
        if(j1 < 0 || j2 < 0 || j1 >=m || j2 >= m) return -1e8;
        if(row == n-1){
            if(j1 == j2){
                return grid[row][j1];
            }else{
                return grid[row][j1] + grid[row][j2];
            }
        }
        
        if(dp[row][j1][j2] != -1) return dp[row][j1][j2];
        
        int max_chocolates = -1e8;
        for(int dj1 = -1; dj1 <= 1; dj1++){
            for(int dj2 = -1; dj2 <= 1; dj2++){
                int value = 0;
                if(j1 == j2){
                    value += grid[row][j1];
                }else{
                    value += grid[row][j1] + grid[row][j2];
                }
                value = value + f(row + 1, j1 + dj1, j2 + dj2, n, m, grid, dp);
                max_chocolates = max(max_chocolates, value);
            }
        }
        
        return dp[row][j1][j2] = max_chocolates;
        
    }
  
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return f(0, 0, m-1, n, m, grid, dp);
    }
};