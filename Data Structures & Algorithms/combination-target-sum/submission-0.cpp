class Solution {
public:
    vector<vector<int>> result;

    void dfs(vector<int>& nums, int i, int target, vector<int>& combo) {

        if (target == 0) {
            result.push_back(combo);
            return;
        }

        if (target < 0 || i == nums.size()) return;

        combo.push_back(nums[i]);
        dfs(nums, i, target - nums[i], combo);
        combo.pop_back();
        dfs(nums, i + 1, target, combo);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> combo;
        dfs(nums, 0, target, combo);
        return result;
    }
};
