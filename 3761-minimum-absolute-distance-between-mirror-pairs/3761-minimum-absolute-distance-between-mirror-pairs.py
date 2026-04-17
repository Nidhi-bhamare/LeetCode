class Solution(object):
    def minMirrorPairDistance(self, nums):
        def reverse_num(x):
            return int(str(x)[::-1])
        
        index_map = {}
        min_dist = float('inf')
        
        for i in range(len(nums)):
            # check if current number matches any previous reversed number
            if nums[i] in index_map:
                min_dist = min(min_dist, i - index_map[nums[i]])
            
            # store reverse of current number
            rev = reverse_num(nums[i])
            index_map[rev] = i
        
        return min_dist if min_dist != float('inf') else -1