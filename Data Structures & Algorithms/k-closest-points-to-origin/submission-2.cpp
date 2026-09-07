class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto less = [] (vector<int> a, vector<int> b) {
            double dist_a = sqrt((a[0] * a[0] + a[1] * a[1]));
            double dist_b = sqrt((b[0]* b[0] + b[1] * b[1]));
            return dist_a < dist_b;
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(less)> heap(less);

        for (vector<int> point : points) {
            heap.push(point);
            if (heap.size() > k) heap.pop();
        }
        vector<vector<int>> result;
        while (!heap.empty()) {
            result.push_back(heap.top());
            heap.pop();
        }
        return result;
    }
};
