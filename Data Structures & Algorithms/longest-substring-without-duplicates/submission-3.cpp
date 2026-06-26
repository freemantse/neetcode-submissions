class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> seen;
        int length = 0;
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            if (seen.count(s[r])) {
                l = max(l, seen[s[r]] + 1);
            }
            seen[s[r]] = r;
            length = max(length, r - l + 1);
        }
        return length;
    }
};
