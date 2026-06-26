from typing import List
from bisect import bisect_left

class Fenwick:
    def __init__(self, n):
        self.bit = [0] * (n + 1)

    def update(self, idx, val):
        while idx < len(self.bit):
            self.bit[idx] += val
            idx += idx & -idx

    def query(self, idx):
        res = 0
        while idx > 0:
            res += self.bit[idx]
            idx -= idx & -idx
        return res


class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        n = len(nums)

        # Prefix sums: +1 for target, -1 otherwise
        prefix = [0]
        curr = 0

        for num in nums:
            curr += 1 if num == target else -1
            prefix.append(curr)

        # Coordinate compression
        values = sorted(set(prefix))

        ft = Fenwick(len(values))
        ans = 0

        for x in prefix:
            idx = bisect_left(values, x) + 1

            # Count previous prefix sums strictly smaller
            ans += ft.query(idx - 1)

            ft.update(idx, 1)

        return ans