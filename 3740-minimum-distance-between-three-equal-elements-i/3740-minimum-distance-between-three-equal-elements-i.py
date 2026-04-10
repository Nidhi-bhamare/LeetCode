class Solution(object):
    def minimumDistance(self, nums):
        from collections import defaultdict
        
        index_map = defaultdict(list)
        
        # Step 1: store indices
        for i, num in enumerate(nums):
            index_map[num].append(i)
        
        ans = float('inf')
        
        # Step 2: check each number
        for indices in index_map.values():
            if len(indices) >= 3:
                # Step 3: check consecutive triplets
                for i in range(len(indices) - 2):
                    a = indices[i]
                    b = indices[i + 1]
                    c = indices[i + 2]
                    
                    # distance = 2 * (c - a)
                    dist = 2 * (c - a)
                    ans = min(ans, dist)
        
        return ans if ans != float('inf') else -1