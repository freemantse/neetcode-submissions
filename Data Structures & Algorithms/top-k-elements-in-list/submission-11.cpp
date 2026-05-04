class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            counts[nums[i]]++;
        }
        vector<vector<int>> bucket(n+1);
        for (const auto& [num, count] : counts) {
            bucket[count].push_back(num);
        }
        vector<int> output;
        for (int i = bucket.size()-1; i >= 0; i--) {
            for (int j = 0; j < bucket[i].size(); j++) {
                if (output.size() < k) {
                    output.push_back(bucket[i][j]);
                }
            }
        }
        return output;
    }
};
