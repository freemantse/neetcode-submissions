class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = defaultdict(int)
        for x in nums:
            counts[x] += 1

        arr = []
        for num, count in counts.items():
            arr.append([count, num])
        arr.sort()

        output = []
        n = len(arr)
        for i in range(n-1, n-1-k, -1):
            output.append(arr[i][1])
        return output
