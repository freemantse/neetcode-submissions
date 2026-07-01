class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left_max(n);
        vector<int> right_max(n);

        left_max[0] = nums[0];
        right_max[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            if (i % k == 0) {
                left_max[i] = nums[i];
            } else {
                left_max[i] = max(left_max[i - 1], nums[i]);
            }

            if ((n - 1 - i) % k == 0) {
                right_max[n - 1 - i] = nums[n - 1 - i];
            } else {
                right_max[n - 1 - i] = max(right_max[n - i], nums[n - 1 - i]);
            }
        }
        vector<int> result(n - k + 1);
        for (int i  = 0; i < n - k + 1; i++) {
            result[i] = max(right_max[i], left_max[i + k - 1]);
        }

        return result;
    }
};
