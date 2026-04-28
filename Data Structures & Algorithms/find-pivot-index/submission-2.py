class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        total = 0
        for num in nums:
            total += num
        
        n = len(nums)
        leftSum = 0
        for i in range(n):
            rightSum = total - leftSum - nums[i]
            if (leftSum == rightSum):
                return i
            leftSum += nums[i]
        return -1