class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left_bound(n, -1);
        vector<int> right_bound(n, n);
        stack<int> stack;

        for (int i=0; i<n; i++) {
            while (!stack.empty() && heights[i] <= heights[stack.top()]) {
                stack.pop();
            } 
            if (!stack.empty()) {
                left_bound[i] = stack.top();
            }
            stack.push(i);
        }
        while (!stack.empty()) stack.pop();

        for (int i=n-1; i>=0; i--) {
            while (!stack.empty() && heights[i] <= heights[stack.top()]) {
                stack.pop();
            }
            if (!stack.empty()){
                right_bound[i] = stack.top();
            }
            stack.push(i);
        }
        int area = 0;
        for (int i=0; i<n; i++) {
            left_bound[i]++;
            right_bound[i]--;
            area = max(area, heights[i] * (right_bound[i]-left_bound[i]+1));
        }
        return area;
    }
};
