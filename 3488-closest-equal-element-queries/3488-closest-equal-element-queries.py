from collections import defaultdict
import bisect

class Solution(object):
    def solveQueries(self, nums, queries):
        n = len(nums)
        
        mp = defaultdict(list)
        for i, val in enumerate(nums):
            mp[val].append(i)
        
        ans = []
        
        for q in queries:
            val = nums[q]
            indices = mp[val]
            
            if len(indices) == 1:
                ans.append(-1)
                continue
            
            pos = bisect.bisect_left(indices, q)
            
            # neighbors (skip itself)
            left = indices[pos - 1] if pos > 0 else indices[-1]
            
            # IMPORTANT FIX: skip same index
            if pos < len(indices) and indices[pos] == q:
                right = indices[pos + 1] if pos + 1 < len(indices) else indices[0]
            else:
                right = indices[pos] if pos < len(indices) else indices[0]
            
            # distances
            d1 = abs(q - left)
            d2 = abs(q - right)
            
            dist_left = min(d1, n - d1)
            dist_right = min(d2, n - d2)
            
            ans.append(min(dist_left, dist_right))
        
        return ans