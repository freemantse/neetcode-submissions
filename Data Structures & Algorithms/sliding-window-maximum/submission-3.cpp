class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n - k + 1);
        deque<int> que;

        int l = 0, r = 0;
        while (r < n) {
            while (!que.empty() && nums[r] > nums[que.back()]) {
                que.pop_back();
            }
            que.push_back(r);

            if (que.front() < l) {
                que.pop_front();
            }

            if ((r + 1) >= k) {
                result[l] = nums[que.front()];
                l++;
            }
            r++;
        }
        return result;
    }
};
