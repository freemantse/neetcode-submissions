class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> A = nums1, B = nums2;
        if (A.size() > B.size()) swap(A, B);

        int m = A.size(), n = B.size();
        int total = m + n;
        int half = (total + 1) / 2;

        int l = 0, r = m;
        while (l <= r) {
            int i = (l + r) / 2;
            int j = half - i;

            int Aleft = i > 0 ? A[i - 1] : INT_MIN;
            int Aright = i < m ? A[i] : INT_MAX;
            int Bleft = j > 0 ? B[j - 1] : INT_MIN;
            int Bright = j < n ? B[j] : INT_MAX;

            if (Aleft > Bright) {
                r = i - 1;
            } else if (Bleft > Aright) {
                l = i + 1;
            } else {
                return (m + n) % 2 ? max(Aleft, Bleft) : (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            }
        }
        return -1;
    }
};
