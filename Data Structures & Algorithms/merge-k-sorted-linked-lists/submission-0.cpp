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
private:
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        ListNode* prev = nullptr;

        while (curr1 && curr2) {
            if (curr1->val < curr2->val) {
                curr->next = curr1;
                prev = curr;
                curr = curr->next;
                curr1 = curr1->next;
            } else {
                curr->next = curr2;
                prev = curr;
                curr = curr->next;
                curr2 = curr2->next;
            }
        }
        if (curr1) {
            curr->next = curr1;
        } else if (curr2) {
            curr->next = curr2;
        }
        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        for (int i = 1; i < lists.size(); i++) {
            lists[i] = mergeLists(lists[i - 1], lists[i]);
        }

        return lists.back();
    }
};
