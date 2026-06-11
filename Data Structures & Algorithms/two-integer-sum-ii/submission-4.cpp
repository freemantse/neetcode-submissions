class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0, r=numbers.size()-1;
        while (l<r) {
            while (l<r && numbers[l]+numbers[r]>target) {
                r--;
            }
            while (l<r && numbers[l]+numbers[r]<target) {
                l++;
            }
            if (numbers[l]+numbers[r] == target) {
                return {l+1,r+1};
            }
        }
    }
};
