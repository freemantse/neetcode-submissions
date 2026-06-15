class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<double,double>> pair;
        for (int i=0;i<position.size();i++) {
            pair.push_back({position[i],speed[i]});
        }
        sort(pair.rbegin(),pair.rend());
        stack<double> stack;
        for (const auto& p : pair) {
            double time = ((target - p.first) / p.second);
            if (!stack.empty() && time <= stack.top()) {
                continue;
            } else {
                stack.push(time);
            }
        }
        return stack.size();
    }
};
