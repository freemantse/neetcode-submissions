class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        queue<int> q;
        for (int student : students) {
            q.push(student);
        }
        for (int sandwich : sandwiches) {
            int count = 0;
            while (count < n && sandwich != q.front()) {
                q.push(q.front());
                q.pop();
                count++;
            }
            if (sandwich == q.front()) {
                q.pop();
            } else {
                break;
            }  
        }
        return q.size();
    }
};