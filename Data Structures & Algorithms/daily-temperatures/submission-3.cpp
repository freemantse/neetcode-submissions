class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(),0);
        stack<int> stack;

        for (int i = 0; i<temperatures.size(); i++) {
            while (!stack.empty() && temperatures[i] > temperatures[stack.top()]) {
                result[stack.top()] = i - stack.top();
                stack.pop();
            }
            stack.push(i);
        }
        return result;
    }
};
