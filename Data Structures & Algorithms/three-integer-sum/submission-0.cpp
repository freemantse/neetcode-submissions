class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;

        for (int i=0;i<nums.size();i++) {
            if (nums[i] > 0) break;
            if (i>0 && nums[i]==nums[i-1]) continue;

            int target = -nums[i];
            int l=i+1,r=nums.size()-1;
            while (l<r) {
                if (nums[l]+nums[r] > target) {
                    r--;
                }
                else if (nums[l]+nums[r] < target) {
                    l++;
                }
                else {
                    output.push_back({nums[l],nums[i],nums[r]});
                    l++;
                    r--;
                    while (l<r && nums[l] == nums[l-1]) l++;
                }
            }
        }
        return output;
    }
};
