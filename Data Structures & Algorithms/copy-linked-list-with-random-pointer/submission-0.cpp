/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> hash;
        Node* dummy = new Node(0);

        Node* node = dummy;
        Node* curr = head;

        while (curr != nullptr) {
            Node* newNode = new Node(curr->val);
            node->next = newNode;
            hash[curr] = newNode;
            curr = curr->next;
            node = node->next;
        }
        curr = head;
        node = dummy->next;
        while (curr != nullptr) {
            node->random = hash[curr->random];
            node = node->next;
            curr = curr->next;
        }
        Node* new_head = dummy->next;
        delete dummy;
        return new_head;
    }
};
