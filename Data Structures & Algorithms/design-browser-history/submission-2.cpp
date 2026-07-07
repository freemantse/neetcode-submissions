class BrowserHistory {
private:
    vector<string> history;
    int curr;
    int n;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        curr = 0;
        n = 1;
    }
    
    void visit(string url) {
        curr++;
        if (curr == history.size()) {
            history.push_back(url);
            n++;
        } else {
            history[curr] = url;
            n = curr + 1;
        }
    }
    
    string back(int steps) {
        curr = max(0, curr - steps);
        return history[curr];
    }
    
    string forward(int steps) {
        curr = min(n - 1, curr + steps);
        return history[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */