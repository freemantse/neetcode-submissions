class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, int i) {
        if (i == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[i])
                continue;
            swap(nums[i], nums[j]);
            backtrack(nums, i + 1);
        }

        for (int j = nums.size() - 1; j > i; j--) {
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return result;
    }
};