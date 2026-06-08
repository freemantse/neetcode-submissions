class Solution {
public:
    int maxArea(vector<int>& heights) {
        int largest = 0;
        int i=0, j=heights.size()-1;

        while (i<j) {
            int capacity = (j-i) * min(heights[i],heights[j]);
            largest = max(largest, capacity);
            if (heights[i]<heights[j]) {
                i++;
            } else {
                j--;
            }
        }
        return largest;
    }
};
