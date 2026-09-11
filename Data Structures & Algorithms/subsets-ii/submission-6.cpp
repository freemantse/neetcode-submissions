class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, int i, vector<int>& subset) {
        result.push_back(subset);

        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j - 1]) 
                continue;
            
            subset.push_back(nums[j]);
            backtrack(nums, j + 1, subset);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        backtrack(nums, 0, subset);
        return result;
    }
};
