from collections import defaultdict
class Solution:
    def totalElements(self, arr):
        l = 0
        r = 0
        mapp = defaultdict(int)
        maxlen = 0
        
        while r < len(arr):
            mapp[arr[r]] += 1
            
            while len(mapp) > 2:
                mapp[arr[l]] -= 1
                if mapp[arr[l]] == 0:
                    del mapp[arr[l]]
                l+=1
            
            maxlen = max(maxlen, r-l+1)
            r+=1
            
        return maxlen