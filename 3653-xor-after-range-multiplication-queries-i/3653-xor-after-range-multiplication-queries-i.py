class Solution(object):
    def xorAfterQueries(self, nums, queries):
        MOD = 10**9 + 7
        
        arr = nums[:]   

        for li, ri, ki, vi in queries:
            idx = li
            
            while idx <= ri:
                arr[idx] = (arr[idx] * vi) % MOD
                idx += ki

        result = 0
        for num in arr:
            result ^= num

        return result