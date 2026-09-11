class Solution {
public:
    void dfs(vector<int>& nums, int i, vector<vector<int>>& result, vector<int>& subset, set<vector<int>>& seen) {
        if (i == nums.size()) {
            if (!seen.contains(subset)) {
                seen.insert(subset);
                result.push_back(subset);
            }
            return;
        } 
        subset.push_back(nums[i]);
        dfs(nums, i + 1, result, subset, seen);
        subset.pop_back();
        dfs(nums, i + 1, result, subset, seen);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> seen;
        vector<vector<int>> result;
        vector<int> subset;
        dfs(nums, 0, result, subset, seen);
        return result;
    }
};
