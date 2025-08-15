#User function Template for python3
class Solution:
    def helper(self, i, dp, height):
        if i == 0:
            return 0
        
        if dp[i] != -1:
            return dp[i]
        
        left = abs(height[i] - height[i-1]) + self.helper(i-1, dp, height)
        right = 1e9
        if i > 1:
            right = abs(height[i] - height[i-2]) + self.helper(i-2, dp, height)
        
        dp[i] = min(left, right)
        
        return dp[i]
    
    def minCost(self, height):
        n = len(height)
        dp = [-1] * n
        return self.helper(n-1, dp, height)