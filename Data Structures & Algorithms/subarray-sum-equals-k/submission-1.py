class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        map = {0:1}
        total = currSum = 0

        for num in nums:
            currSum += num
            diff = currSum - k

            total += map.get(diff,0)
            map[currSum] = 1 + map.get(currSum,0)
        return total


