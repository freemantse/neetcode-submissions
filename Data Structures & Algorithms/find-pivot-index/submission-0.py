class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        self.prefix = []
        sum = 0
        for num in nums:
            sum += num
            self.prefix.append(sum)

        n = len(self.prefix)
        if (self.prefix[n-1]-self.prefix[0] == 0): 
            return 0

        for i in range(1, n):
            if ((self.prefix[n-1]-self.prefix[i]) == self.prefix[i-1]):
                return i
        return -1