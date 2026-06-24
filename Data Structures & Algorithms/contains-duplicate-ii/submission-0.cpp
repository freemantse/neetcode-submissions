class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash_map;
        for (int i = 0; i < nums.size(); i++) {
            int j = i - k - 1;
            if (j >= 0) {
                hash_map.erase(nums[j]);
            }
            if (hash_map.count(nums[i])) {
                return true;
            }
            hash_map[nums[i]] = i;
        }
        return false;
    }
};