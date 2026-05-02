class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hash_map = {}

        arr = [0] * 26
        for i in range(len(strs)):
            arr[:] = [0] * 26
            for x in strs[i]:
                arr[ord(x) - ord('a')] += 1
            key = tuple(arr)
            if hash_map.get(key):
                hash_map[key].append(strs[i])
            else:
                hash_map[key] = [strs[i]]
        
        return list(hash_map.values())