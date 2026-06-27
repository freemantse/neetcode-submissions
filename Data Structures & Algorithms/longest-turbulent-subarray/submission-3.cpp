class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int count = 0, length = 0, sign = -1;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                count = (sign == 1) ? count + 1 : 1;
                sign = 0;
            } else if (arr[i] < arr[i + 1]) {
                count = (sign == 0) ? count + 1 : 1;
                sign = 1;
            } else {
                count = 0;
                sign = -1;
            }
            length = max(length, count);
        }
        return length + 1;
    }
};