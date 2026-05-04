class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        
        cout << "nums = [";
        for (int i = 0; i < nums.size(); i++){
            cout << nums[i] << ',';
        }
        cout << ']' << endl;

        int res = 0, curr = nums[0], streak = 0, i = 0;
        while (i < nums.size()) {
            if (nums[i] != curr) {
                curr = nums[i];
                streak = 0;
            }
            while (nums[i] == curr) {
                i++;
            }
            streak++;
            curr++;
            res = max(streak, res);
        }
        return res;
    }
};
