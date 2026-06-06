class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hash_map;
        for (const auto& str : strs) {
            vector<int> count(26,0);
            for (const char& c: str) {
                count[c-'a']++;
            }
            string key = to_string(count[0]);
            for (int i=1; i<26; i++) {
                key += count[i];
            }
            hash_map[key].push_back(str);
        }
        vector<vector<string>> output;
        for (const auto& pair: hash_map) {
            output.push_back(pair.second);
        }
        return output;
    }
};
