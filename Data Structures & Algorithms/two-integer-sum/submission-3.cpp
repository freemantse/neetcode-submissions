class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> diff_map;
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (diff_map.count(diff)) {
                return {diff_map[diff], i};
            }
            diff_map[nums[i]] = i;
        }
    }
};
