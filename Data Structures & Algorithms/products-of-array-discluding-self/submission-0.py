class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        self.prefix = [1] * n
        self.suffix = [1] * n
        output = [1] * n

        for i in range(n-1): 
            self.prefix[i+1] = self.prefix[i] * nums[i]
        print(self.prefix)

        for i in range(n-1,0,-1):
            self.suffix[i-1] = self.suffix[i] * nums[i]
        print(self.suffix)

        for i in range(n):
            output[i] = (self.suffix[i] * self.prefix[i])
        return output
