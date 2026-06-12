class MinStack {
private:
    std::stack<int> stack;
    std::stack<int> prefix_min;
public:
    MinStack() {}
    
    void push(int val) {
        stack.push(val);
        prefix_min.push(min(val, prefix_min.empty() ? val : prefix_min.top()));
    }
    
    void pop() {
        stack.pop();
        prefix_min.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return prefix_min.top();
    }
};
