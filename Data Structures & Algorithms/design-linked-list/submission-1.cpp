class MyLinkedList {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int val) : val{val}, next{nullptr} {};
    };

public:
    ListNode* head;
    int size;
    MyLinkedList() {
        head = new ListNode(0);
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        ListNode* curr = head;
        for (int i = -1; i < index; i++) {
            curr = curr->next;            
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head->next;
        head->next = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* curr = head;
        for (int i = 0; i < size; i++) {
            curr = curr->next;
        }
        ListNode* newNode = new ListNode(val);
        curr->next = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        ListNode* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;            
        }
        ListNode* newNode = new ListNode(val);
        ListNode* temp = curr->next;
        curr->next = newNode;
        newNode->next = temp;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        ListNode* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;            
        }
        ListNode* temp = curr->next;
        curr->next = temp->next;
        temp->next = nullptr;
        delete temp;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */