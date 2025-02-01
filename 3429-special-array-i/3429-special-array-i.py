class Solution(object):
    def isArraySpecial(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        for i in range(1, len(nums)):
            if (nums[i] % 2) == (nums[i - 1] % 2):  # Check if adjacent elements have the same parity
                return False
        return True  # All adjacent elements have different parity

# Example usage
solution = Solution()

nums1 = [1]
nums2 = [2, 1, 4]
nums3 = [4, 3, 1, 6]

print(solution.isArraySpecial(nums1))  # Output: True
print(solution.isArraySpecial(nums2))  # Output: True
print(solution.isArraySpecial(nums3))  # Output: False
