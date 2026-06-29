class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        unordered_map<char,int> t_count;
        for (const char& c : t) {
            t_count[c]++;
        }
        int num_unique = t_count.size();

        unordered_map<char,int> s_count;
        int best_l = -1;
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
                    best_l = l;
                }
                if (s_count[s[l]] == t_count[s[l]]) {
                    match--;
                }
                s_count[s[l]]--;
                l++;
            }
            r++;
        }
        return (best_l == -1) ? "" : s.substr(best_l, length);

    }
};
