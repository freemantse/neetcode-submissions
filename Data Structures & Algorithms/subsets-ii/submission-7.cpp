class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result = {{}};
        sort(nums.begin(), nums.end());
        int prevIdx = 0;
        int idx = 0;

        for (int i = 0; i < nums.size(); i++) {
            idx = (i > 0 && nums[i] == nums[i - 1]) ? prevIdx : 0;
            prevIdx = result.size();
            for (int j = idx; j < prevIdx; j++) {
                vector<int> subset = result[j];
                subset.push_back(nums[i]);
                result.push_back(subset);
            }
        }
        return result;
    }
};
