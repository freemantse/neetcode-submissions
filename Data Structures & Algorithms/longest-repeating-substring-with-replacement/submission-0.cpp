class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> char_set(s.begin(), s.end());
        int length = 0;

        for (char c : char_set) {
            int count = 0;
            int l = 0;
            for (int r = 0; r < s.size(); r++) {
                if (s[r] == c) {
                    count++;
                }
                
                while (r - l + 1 - count > k) {
                    if (s[l] == c) {
                        count--;
                    }
                    l++;
                }
                length = max(length, r - l + 1);
            }
        }
        return length;
    }
};
