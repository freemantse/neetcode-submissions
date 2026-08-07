class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (minHeap.empty()) {
            minHeap.push(num);
            return;
        }
        if (num > minHeap.top()) {
            minHeap.push(num);
            if (minHeap.size() - maxHeap.size() > 1) {
                int top = minHeap.top();
                minHeap.pop();
                maxHeap.push(top);
            }
        } else {
            maxHeap.push(num);
            if (maxHeap.size() - minHeap.size() > 1) {
                int top = maxHeap.top();
                maxHeap.pop();
                minHeap.push(top);
            }
        }
    }
    
    double findMedian() {
        int sizeMin = minHeap.size();
        int sizeMax = maxHeap.size();
        if (sizeMin > sizeMax) return minHeap.top();
        else if (sizeMax > sizeMin) return maxHeap.top();
        else return (double)(minHeap.top() + maxHeap.top()) / 2;
    }
};
