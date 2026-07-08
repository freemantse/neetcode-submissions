class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> count(nums.size(), 0);
        for (int num : nums) {
            count[num]++;
            if (count[num] > 1) return num;
        }
    }
};
