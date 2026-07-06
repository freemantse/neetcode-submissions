class BrowserHistory {
    struct PageNode {
        string url;
        PageNode* prev;
        PageNode* next;
        PageNode(string url, PageNode* prev = nullptr, PageNode* next = nullptr) : url{url}, prev{prev}, next{next} {};
    };
public:
    PageNode* currPage;
    int forwardStep;
    int backwardStep;

    BrowserHistory(string homepage) {
        currPage = new PageNode(homepage);
        forwardStep = 0;
        backwardStep = 0;
    }
    
    void visit(string url) {
        PageNode* newPage = new PageNode(url);
        PageNode* curr = currPage->next;
        while (curr != nullptr) {
            PageNode* temp = curr->next;
            delete curr;
            curr = temp;
        }
        forwardStep = 0;
        currPage->next = newPage;
        newPage->prev = currPage;
        currPage = currPage->next;
        backwardStep++;
    }
    
    string back(int steps) {
        if (steps > backwardStep) {
            steps = backwardStep;
        }
        for (int i = 0; i < steps; i++) {
            currPage = currPage->prev;
            backwardStep--;
            forwardStep++;
        }
        return currPage->url;
    }
    
    string forward(int steps) {
        if (steps > forwardStep) {
            steps = forwardStep;
        }
        for (int i = 0; i < steps; i++) {
            currPage = currPage->next;
            forwardStep--;
            backwardStep++;
        }
        return currPage->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */