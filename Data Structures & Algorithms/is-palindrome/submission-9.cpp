class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length()-1;
        while (j>i) {
            while (j>i && !isalnum(s[i])) i++;
            while (j>i && !isalnum(s[j])) j--;

            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
