class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(),nums.end());

        int longest = 0;

        for (int num: nums) {
            if (!num_set.count(num-1)) {
                int length = 1;
                while (num_set.count(num+length)) {
                    length++;
                }
            longest = max(longest,length);
            }
        }
        return longest;
        
    }
};
