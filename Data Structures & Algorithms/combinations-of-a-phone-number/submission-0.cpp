class Solution {
public:
    vector<string> result;
    vector<string> charMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtrack(string& digits, int i, string& combo) {
        if (combo.size() == digits.size()) {
            result.push_back(combo);
            return;
        }

        for (char curr : charMap[digits[i] - '0']) {
            combo.push_back(curr);
            backtrack(digits, i + 1, combo);
            combo.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        string combo = "";
        backtrack(digits, 0, combo);
        return result;
    }
};
