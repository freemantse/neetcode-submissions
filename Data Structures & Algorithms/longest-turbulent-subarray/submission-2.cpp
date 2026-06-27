class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int l = 0, r = 1, length = 1;
        string prev = "";
        while (r < arr.size()) {
            if (arr[r - 1] > arr[r] && prev != ">") {
                length = max(length, r - l + 1);
                r++;
                prev = ">";
            } else if (arr[r - 1] < arr[r] && prev != "<") {
                length = max(length, r - l + 1);
                r++;
                prev = "<";
            } else {
                r = (arr[r] == arr[r - 1]) ? r + 1 : r;
                l = r - 1;
                prev = "";
            }
        }
        return length;
    }
};