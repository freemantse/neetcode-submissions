class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        int cut = 0;

        while (l <= r) {
            int m = (r - l) / 2 + l;
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else if (nums[m] < nums[r]) {
                r = m;
            } else {
                cut = m;
                break;
            }
        }
        r = n-1;
        if (target < nums[r]) {
            l = cut;
        } else if (target > nums[r]) {
            l = 0;
            r = cut - 1;
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
