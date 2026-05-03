class Solution:

    def encode(self, strs: List[str]) -> str:
        for i in range(len(strs)):
            n = str(len(strs[i]))
            strs[i] = n + "#" + strs[i]
        print("".join(strs))
        return "".join(strs)

    def decode(self, s: str) -> List[str]:
        strs = []
        i = 0
        while i < len(s):
            curr = i
            while s[curr] != '#':
                curr += 1
            n = int(s[i:curr])
            string = s[curr+1:curr+1+n]
            strs.append(string)
            i = curr + n + 1 
        return strs
                    
        