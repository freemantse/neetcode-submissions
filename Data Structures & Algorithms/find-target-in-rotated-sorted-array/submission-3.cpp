class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;

        while (l < r) {
            int m = (r - l) / 2 + l;
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            } 
        }
        int pivot = l;
        l = 0;
        r = nums.size()-1;
        if (target < nums[r]) {
            l = pivot;
        } else if (target > nums[r]) {
            r = pivot - 1;
        } else {
            return r;
        }

        while (l <= r) {
            int m = (r - l) / 2 + l;
            if (nums[m] < target) {
                l = m + 1;
            } else if (nums[m] > target) {
                r = m - 1;
            } else {
                return m;
            }
        }
        return -1;
    }
};
