class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        prefix = [1] * n
        suffix = [1] * n
        output = [1] * n

        for i in range(n-1): 
            prefix[i+1] = prefix[i] * nums[i]

        for i in range(n-1,0,-1):
            suffix[i-1] = suffix[i] * nums[i]

        for i in range(n):
            output[i] = suffix[i] * prefix[i]
        return output
