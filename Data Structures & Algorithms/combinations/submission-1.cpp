class Solution {
public:
    vector<vector<int>> result;
    int n;

    void backtrack(int i, int k, vector<int>& combo) {
        if (combo.size() == k) {
            result.push_back(combo);
            return;
        }
        
        for (int j = i; j <= n; j++) {
            combo.push_back(j);
            backtrack(j + 1, k, combo);
            combo.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> combo;
        this->n = n;
        backtrack(1, k, combo);
        return result;
    }
};