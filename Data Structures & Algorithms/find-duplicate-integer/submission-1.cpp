class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> count(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
            if (count[nums[i]] > 1) return nums[i];
        }
    }
};
