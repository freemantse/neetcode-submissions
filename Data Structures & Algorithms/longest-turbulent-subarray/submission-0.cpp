class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int l = 0;
        int length = 1;
        int sign = 0;
        for (int r = 1; r < arr.size(); r++) {
            if ((sign == 1 && arr[r] > arr[r - 1]) || 
                (sign == -1 && arr[r] < arr[r - 1])) {
                l = r - 1;
            } else if (arr[r] == arr[r - 1]) {
                l = r;
            }

            if (arr[r] > arr[r - 1]) {
                sign = 1;
            } else if (arr[r] < arr[r - 1]) {
                sign = -1;
            }

            length = max(r - l + 1, length);
        }
        return length;
    }
};