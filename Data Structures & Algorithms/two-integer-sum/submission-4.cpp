class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> data;

        for (int i=0; i<nums.size(); i++) {
            int x = target - nums[i];
            if (data.count(x)) {
                return {data[x],i};
            }
            data[nums[i]] = i;
        }
    }
};
