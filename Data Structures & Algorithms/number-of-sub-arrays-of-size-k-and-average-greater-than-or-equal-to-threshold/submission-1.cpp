class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        threshold *= k;
        int sum = 0, count = 0;
        for (int r = 0; r < arr.size(); r++) {
            sum += arr[r];
            if (r >= k - 1) {
                if (sum >= threshold) count++;

                sum -= arr[r - k + 1];
            }
        }
        return count;
    }
};