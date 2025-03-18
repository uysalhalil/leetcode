from typing import List


class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        set1 = set(nums1)
        set2 = set(nums2)

        def diff(nums: List[int], numset: set) -> List[int]:
            res = set()
            for n in nums:
                if n not in numset:
                    res.add(n)
            return list(res)

        res = []
        res.append(diff(nums1, set2))
        res.append(diff(nums2, set1))
        return res
