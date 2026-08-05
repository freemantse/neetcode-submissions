class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> heap;
    int k = 0;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i = 0; i < nums.size(); i++) {
            if (heap.size() == k) {
                if (heap.top() > nums[i]) continue;
                heap.pop();
            }
            heap.push(nums[i]);
        }
    }
    
    int add(int val) {
        if (heap.size() == k) {
            if (heap.top() > val) return heap.top();
            heap.pop();
        }
        heap.push(val);
        return heap.top();
    }
};
