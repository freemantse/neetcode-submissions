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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        auto compareNode = [] (ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(compareNode)> minHeap(compareNode);

        for (ListNode* node : lists) {
            minHeap.push(node);
        }

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while (!minHeap.empty()) {
            ListNode* top = minHeap.top();
            minHeap.pop();
            curr->next = top;
            curr = curr->next;
            if (top->next) minHeap.push(top->next);
        }
        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};
