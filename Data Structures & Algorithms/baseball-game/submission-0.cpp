class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stack;
        for (string operation: operations) {
            if (operation == "+") {
                int temp = stack.back();
                stack.pop_back();
                int sum = stack.back() + temp;
                stack.push_back(temp);
                stack.push_back(sum);
            } else if (operation == "D") {
                stack.push_back(2*stack.back());
            } else if (operation == "C") {
                stack.pop_back();
            } else {
                stack.push_back(stoi(operation));
            }
        }
        return accumulate(stack.begin(),stack.end(),0);
    }
};