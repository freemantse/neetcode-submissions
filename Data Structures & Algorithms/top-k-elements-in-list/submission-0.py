class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = defaultdict(int)
        output = []

        for x in nums:
            count[x] += 1

        while k > 0:
            max_key = max(count,key=count.get)            
            output.append(max_key)
            count.pop(max_key)
            k -= 1
        
        return output
        

        