class Solution {
public:
    vector<vector<int>> result = {};

    void backtrack(vector<int>& nums, int i, int target, vector<int>& subset) {
        if (target == 0) {
            result.push_back(subset);
            return;
        }   

        if (target < 0 || i == nums.size()) return;

        subset.push_back(nums[i]);
        backtrack(nums, i, target - nums[i], subset);
        subset.pop_back();
        backtrack(nums, i + 1, target, subset);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> subset = {};
        backtrack(nums, 0, target, subset);
        return result;
    }
};
