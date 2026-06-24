class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0, count = 0;
        for (int i = 0; i < k - 1; i++) {
            sum += arr[i];
        }
        
        for (int l = 0; l <= arr.size() - k; l++) {
            sum += arr[l + k - 1];
            if (sum / k >= threshold) count++;
            sum -= arr[l];
        }
        return count;
    }
};