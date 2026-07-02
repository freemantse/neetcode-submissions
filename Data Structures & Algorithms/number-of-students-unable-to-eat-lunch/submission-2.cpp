class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int result = students.size();
        vector<int> count(2);
        for (const int& student : students) {
            count[student]++;
        }

        for (const int& sandwich : sandwiches) {
            if (count[sandwich] > 0) {
                count[sandwich]--;
                result--;
            } else {
                break;
            }
        }
        return result;
    }
};