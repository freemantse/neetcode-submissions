class Solution {
public:
    int quickSelect(vector<int>& nums, int left, int right, int k) {
        int pivot = nums[right];
        int j = left;
        for (int i = left; i < right; i++) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
        swap(nums[right], nums[j]);

        if (j > k)
            return quickSelect(nums, left, j - 1, k);
        else if (j < k) 
            return quickSelect(nums, j + 1, right, k);
        else
            return pivot;
    }

    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
};
