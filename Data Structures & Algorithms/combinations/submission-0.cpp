class Solution {
public:
    vector<vector<int>> result;
    int n;

    void backtrack(int i, int k, vector<int>& combo) {
        if (combo.size() == k) {
            result.push_back(combo);
            return;
        }

        if (i > n) return;

        combo.push_back(i);
        backtrack(i + 1, k, combo);
        combo.pop_back();
        backtrack(i + 1, k, combo);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> combo;
        this->n = n;
        backtrack(1, k, combo);
        return result;
    }
};