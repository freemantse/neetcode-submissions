class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        occur = set()

        for num in nums:
            if num in occur:
                return True
            occur.add(num)
        return False
        