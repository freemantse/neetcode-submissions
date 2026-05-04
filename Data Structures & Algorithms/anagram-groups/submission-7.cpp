class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       map<vector<int>, vector<string>> group;

       for (string str : strs) {
        vector<int> key(26);
        for (char c : str) {
            key[c - 'a']++;
        }
        group[key].push_back(str);
       }
        vector<vector<string>> output;
        for (auto& [key, val] : group) {
            output.push_back(val);
        }
        return output;
    }
};
