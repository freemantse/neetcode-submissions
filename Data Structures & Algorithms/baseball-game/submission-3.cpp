class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stack;
        int result = 0;

        for (const string& op : operations) {
            if (op == "+") {
                int top = stack.back();
                stack.pop_back();
                int new_top = top + stack.back();
                stack.push_back(top);
                stack.push_back(new_top);
                result += new_top;
            } else if (op == "D") {
                int new_top = 2*(stack.back());
                stack.push_back(new_top);
                result += new_top;
            } else if (op == "C") {
                result -= stack.back();
                stack.pop_back();
            } else {
                stack.push_back(stoi(op));
                result += stoi(op);
            }
        }
        return result;
    }
};