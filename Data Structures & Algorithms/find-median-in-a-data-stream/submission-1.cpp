class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {}
    
    void addNum(int num) {
            minHeap.push(num);
            if (!maxHeap.empty() && minHeap.top() < maxHeap.top()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        
            if (minHeap.size() > maxHeap.size() + 1) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
    
    double findMedian() {
        int sizeMin = minHeap.size();
        int sizeMax = maxHeap.size();
        if (sizeMin > sizeMax) return minHeap.top();
        else if (sizeMax > sizeMin) return maxHeap.top();
        else return (minHeap.top() + maxHeap.top()) / 2.0;
    }
};
