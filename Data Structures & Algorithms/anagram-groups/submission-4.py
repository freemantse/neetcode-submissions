class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        output = []
        hash_map = {}

        for i in range(len(strs)):
            arr = [0] * 26
            for x in strs[i]:
                arr[ord(x) - ord('a')] += 1
            key = tuple(arr)
            if key in hash_map:
                hash_map[key].append(strs[i])
            else:
                hash_map[key] = [strs[i]]
        
        for value in hash_map.values():
            output.append(value)
        return output







