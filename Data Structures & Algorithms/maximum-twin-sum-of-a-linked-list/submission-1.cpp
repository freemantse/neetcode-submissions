/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* fast = head, *slow = head, *prev = nullptr;
        while (fast && fast->next) {
            fast = fast->next->next;
            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        int result = 0;
        while (slow) {
            result = max(result, slow->val + prev->val);
            slow = slow->next;
            prev = prev->next;
        }
        return result;
    }
};