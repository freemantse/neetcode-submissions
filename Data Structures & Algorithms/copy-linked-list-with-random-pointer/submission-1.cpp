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

        Node* curr = head;

        while (curr != nullptr) {
            Node* newNode = new Node(curr->val);
            hash[curr] = newNode;
            curr = curr->next;
        }

        curr = head;
        while (curr != nullptr) {
            Node* newNode = hash[curr];
            newNode->random = hash[curr->random];
            newNode->next = hash[curr->next];
            curr = curr->next;
        }
        
        return hash[head];
    }
};
