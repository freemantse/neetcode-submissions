class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (char i: s) {
            if (i == '(' || i == '{' || i == '[') {
                stack.push_back(i);
            } else {
                if (!stack.empty()) {
                    char top = stack.back();

                if (i == ')') {
                    if (top != '(') return false;      
                } else if (i == '}') {
                    if (top != '{') return false;
                } else {
                    if (top != '[') return false;
                }
                    stack.pop_back();
                } else return false;    
            }
        }
        return stack.empty();
    }
};
