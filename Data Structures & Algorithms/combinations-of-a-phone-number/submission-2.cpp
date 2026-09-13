class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> result = {""};
        vector<string> charMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        for (char digit : digits) {
            vector<string> temp = {};
            for (string& currString : result) {
                for (char c : charMap[digit - '0']) {
                    temp.push_back(currString + c);
                }
            }
            result = temp;
        }
        return result;
    }
};
