class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> pre_max(n), suff_max(n);
        pre_max[0] = 0;
        for (int i=1;i<n;i++) {
            pre_max[i] = max(pre_max[i-1],height[i-1]);
        }
        // [0,0,2,2,3,3,3,3,3,3]
        suff_max[n-1] = 0;
        for (int i=n-2;i>=0;i--) {
            suff_max[i] = max(suff_max[i+1], height[i+1]);
        }
        // [3,3,3,3,3,3,3,2,1,0]

        int output = 0;
        for (int i = 0;i<n;i++) {
            int res = (min(pre_max[i], suff_max[i]) - height[i]);
            if (res > 0) {
                output += res;
            }
        }
        return output;
    }
};
