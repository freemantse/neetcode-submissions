class Solution {
public:
    vector<string> result = {};
    vector<string> charMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtrack(string& digits, int i, string combo) {
        if (combo.size() == digits.size()) {
            result.push_back(combo);
            return;
        }
        string chars = charMap[digits[i] - '0'];
        for (char curr : chars) {
            backtrack(digits, i + 1, combo + curr);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return result;
        backtrack(digits, 0, "");
        return result;
    }
};
