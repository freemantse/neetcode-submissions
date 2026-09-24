class Solution {
public:
    vector<vector<int>> result;

    void backtrack (vector<int>& nums, vector<int>& curr, vector<bool>& pick) {
        if (curr.size() == nums.size()) {
            result.push_back(curr);
            return;
        }
            
        for (int i = 0; i < nums.size(); i++) {
            if (!pick[i]) {
                curr.push_back(nums[i]);
                pick[i] = true;
                backtrack(nums, curr, pick);
                curr.pop_back();
                pick[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<bool> pick(nums.size(), false);
        vector<int> curr;
        backtrack(nums, curr, pick);
        return result;
    }
};
