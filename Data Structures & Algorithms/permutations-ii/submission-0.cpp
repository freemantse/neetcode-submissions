class Solution {
public:
    vector<vector<int>> result;
    vector<bool> visit;

    void backtrack(vector<int>& nums, vector<int>& perm) {
        if (perm.size() == nums.size()) {
            result.push_back(perm);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
                if (visit[i] || (i > 0 && nums[i] == nums[i - 1] && !visit[i - 1]))
                    continue;
                perm.push_back(nums[i]);
                visit[i] = true;
                backtrack(nums, perm);
                perm.pop_back();
                visit[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        visit.assign(nums.size(), false);
        sort(nums.begin(), nums.end());
        vector<int> perm;
        backtrack(nums, perm);
        return result;
    }
};