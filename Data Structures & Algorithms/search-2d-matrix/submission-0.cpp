class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m - 1;

        while (top <= bottom) {
            int row = (top + bottom) / 2;
            if (target > matrix[row][n-1]) {
                top = row + 1;
            } else if (target < matrix[row][0]) {
                bottom = row-1;
            } else break;
        }

        if (top > bottom) return false;
        
        int row = (top + bottom) / 2;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l+r)/2;
            if (matrix[row][mid] > target) {
                r = mid - 1;
            } else if (matrix[row][mid] < target) {
                l = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
