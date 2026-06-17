class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(),piles.end());
        int result = r;
        while (l <= r) {
            int k = (l + r) / 2;
            long long total_time = 0;
            for (int p : piles) {
                total_time += ceil(static_cast<double>(p) / k);
            }
            if (total_time <= h) {
                result = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }   
        return result;
    }
};
