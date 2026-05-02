class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = defaultdict(int)
        for x in nums:
            counts[x] += 1
        
        min_heap = []
        for num, count in counts.items():
            heapq.heappush(min_heap, (count, num))
            if len(min_heap) > k:
                heapq.heappop(min_heap)

        output = []
        for i in range(len(min_heap)):
            output.append(heapq.heappop(min_heap)[1])
        return output

        