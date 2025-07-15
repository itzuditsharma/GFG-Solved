from collections import defaultdict
class Solution:
    def totalElements(self, arr):
        # Code here
        n = len(arr)
        mapp = defaultdict(int)
        l = 0
        r = 0
        maxones = 0
        
        while r < n:
            mapp[arr[r]] += 1
            
            while len(mapp) > 2:
                mapp[arr[l]] -= 1
                if mapp[arr[l]] == 0:
                    del mapp[arr[l]]
                l+=1
            
            maxones = max(maxones, r-l+1)
            r+=1
            
        return maxones
                
            