import heapq
class Solution:
    def minMaxDist(self, stations, k):
        pq = []
        n = len(stations)
        howMany = [0] * (n-1)
        if n <= 1:
            return 0.0
        
        for i in range(n-1):
            diff = stations[i+1] - stations[i]
            heapq.heappush(pq, (-diff, i))
            
        for gasStation in range(k):
            sec_len, index = heapq.heappop(pq)
            howMany[index] += 1
            diff = stations[index+1] - stations[index]
            new_sec_len = diff / (howMany[index] + 1)
            heapq.heappush(pq, (-new_sec_len, index))
            
        ans, _ = heapq.heappop(pq)
        return -ans
        