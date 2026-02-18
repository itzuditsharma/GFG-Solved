class Solution:
    def leaders(self, arr):
        n = len(arr)
        leader = arr[n-1]
        leaders = []
        leaders.append(leader)
        for i in range(n-2, -1, -1):
            if arr[i] >= leader:
                leader = arr[i]
                leaders.append(leader)
        
        return leaders[::-1]