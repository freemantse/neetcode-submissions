class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        unordered_map<char,int> t_count;
        for (int i = 0; i < t.size(); i++) {
            t_count[t[i]]++;
        }
        int num_unique = t_count.size();

        unordered_map<char,int> s_count;
        string substring = "";
        int length = INT_MAX, match = 0;
        int l = 0, r = 0;
        while (r < s.size()) {
            s_count[s[r]]++;
            if (s_count[s[r]] == t_count[s[r]]) {
                match++;
            }
            while (match == num_unique) {
                if (r - l + 1 < length) {
                    length = r - l + 1;
                    substring = string(s.begin() + l, s.begin() + r + 1);
                }
                if (s_count[s[l]] <= t_count[s[l]]) {
                    match--;
                }
                s_count[s[l]]--;
                l++;
            }
            r++;
        }
        return substring;

    }
};
