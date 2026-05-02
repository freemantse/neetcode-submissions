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
        while len(output) < k:
            output.append(arr.pop()[1])
        return output
