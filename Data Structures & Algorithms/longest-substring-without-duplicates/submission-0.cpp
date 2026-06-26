class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int length = 0, max_length = 0;
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            while (seen.count(s[r])) {
                seen.erase(s[l]);
                l++;
                length--;
            }
            seen.insert(s[r]);
            length += 1;
            max_length = max(max_length, length);
        }
        return max_length;
    }
};
