class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> s1_freq(26, 0);
        vector<int> s2_freq(26,0);
        for (int i = 0; i < s1.size(); i++) {
            s1_freq[s1[i] - 'a']++;
            s2_freq[s2[i] - 'a']++;
        }
        if (s2_freq == s1_freq) return true;

        for (int i = 1; i <= (s2.size()-s1.size()); i++) {
            s2_freq[s2[i - 1] - 'a']--;
            s2_freq[s2[i + s1.size() - 1] - 'a']++;

            if (s2_freq == s1_freq) return true;
        }
        return false;
        

    }
};
