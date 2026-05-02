class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = defaultdict(int)
        for num in nums:
            counts[num] += 1
        
        buckets = [[] for _ in range(len(nums)+1)]
        for num, count in counts.items():
            buckets[count].append(num)
            
        output = []
        n = len(buckets)
        for i in range(n-1,-1,-1):
            if len(output) == k:
                return output
            output += buckets[i]

        
