class Solution {
public:
    vector<vector<int>> result = {};

    void backtrack(vector<int>& nums, int i, int target, vector<int>& subset, int currSum) {
        if (currSum == target) {
            result.push_back(subset);
            return;
        }   

        if (currSum > target || i == nums.size()) return;

        subset.push_back(nums[i]);
        backtrack(nums, i, target, subset, currSum + nums[i]);
        subset.pop_back();
        backtrack(nums, i + 1, target, subset, currSum);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> subset = {};
        backtrack(nums, 0, target, subset, 0);
        return result;
    }
};
