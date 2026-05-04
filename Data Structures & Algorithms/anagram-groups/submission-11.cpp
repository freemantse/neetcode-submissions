class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string, vector<string>> group;

       for (string str : strs) {
        vector<int> count(26, 0);
        for (char c : str) {
            count[c -'a']++;
        }
        string key = to_string(count[0]);
        for (int i = 1; i < count.size(); i++) {
            key += ',' + to_string(count[i]);
        }
        group[key].push_back(str);
       }
        vector<vector<string>> output;
        for (const auto& pair : group) {
            output.push_back(pair.second);
        }
        return output;
    }
};
