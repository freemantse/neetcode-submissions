class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        n = len(nums)
        self.prefixSum = [0] * (n+1)
        for i in range(n):
            self.prefixSum[i+1] = self.prefixSum[i] + nums[i]
        print(self.prefixSum)

        for i in range(n):
            if ((self.prefixSum[n]-self.prefixSum[i+1]) == self.prefixSum[i]):
                return i
        return -1