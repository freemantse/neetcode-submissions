class Solution {
public:
    void dfs(vector<int>& nums, int i, vector<vector<int>>& result, vector<int>& subset) {
        if (i == nums.size()) {
            result.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(nums, i + 1, result, subset);
        subset.pop_back();
        dfs(nums, i + 1, result, subset);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        dfs(nums, 0, result, subset);
        return result;
    }
};
