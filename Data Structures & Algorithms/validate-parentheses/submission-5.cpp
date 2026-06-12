class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (char c: s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push_back(c);
            } else {
                if (!stack.empty()) {
                    char top = stack.back();

                if (c == ')') {
                    if (top != '(') return false;      
                } else if (c == '}') {
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
