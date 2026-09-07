class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>,less<int>> heap;

        for (int stone : stones) heap.push(stone);

        while (heap.size() > 1) {
            int y = heap.top();
            heap.pop();
            int x = heap.top();
            heap.pop();

            if (y == x) continue;
            heap.push(y - x);
        }
        return (heap.size() == 0) ? 0 : heap.top() ;
    }
};
