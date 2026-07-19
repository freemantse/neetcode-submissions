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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int total = 0;
        while (curr != nullptr) {
            total++;
            curr = curr->next;
        }
        curr = head;
        ListNode* prev = nullptr;
        for (int i = 0; i < total - n; i++) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == head) {
            head = curr->next;
        } else {
            prev->next = curr->next;
        }
        delete curr;

        return head;
    }
};
