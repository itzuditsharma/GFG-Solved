from collections import defaultdict
class Solution:
    def maxLength(self, nums):
        n = len(nums)
        mapp = defaultdict(int)
        longest = 0
        summ = 0
        
        for i in range(n):
            summ += nums[i]
            remain = summ - 0
            
            if remain == 0:
                longest = max(longest, i+1)
            
            if remain in mapp:
                longest = max(longest, i - mapp[remain])
            
            if summ not in mapp:
                mapp[summ] = i
        
        return longest
        